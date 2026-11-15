class Solution {
public:
    int mergeSort(vector<long long>& prefix, int low, int high, int lower, int upper) {
        if (low >= high) return 0;
        int mid = low + (high - low) / 2;
        int count = mergeSort(prefix, low, mid, lower, upper);
        count += mergeSort(prefix, mid + 1, high, lower, upper);
        int j = mid + 1, k = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (j <= high && prefix[j] - prefix[i] < lower) j++;
            while (k <= high && prefix[k] - prefix[i] <= upper) k++;
            count += k - j;
        }
        vector<long long> temp;
        int i = low, l = mid + 1;
        while (i <= mid && l <= high) {
            if (prefix[i] <= prefix[l])
                temp.push_back(prefix[i++]);
            else
                temp.push_back(prefix[l++]);
        }
        while (i <= mid) temp.push_back(prefix[i++]);
        while (l <= high) temp.push_back(prefix[l++]);
        for (int i = low; i <= high; i++) {
            prefix[i] = temp[i - low];
        }
        return count;
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        return mergeSort(prefix, 0, n, lower, upper);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna