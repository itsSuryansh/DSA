class Solution {
public:
    void merge(vector<int>& a, int l, int m, int r) {
        vector<int> t;
        int i = l, j = m + 1;
        while (i <= m && j <= r) {
            if (a[i] <= a[j])
                t.push_back(a[i++]);
            else
                t.push_back(a[j++]);
        }
        while (i <= m)
            t.push_back(a[i++]);
        while (j <= r)
            t.push_back(a[j++]);
        for (int k = l; k <= r; k++)
            a[k] = t[k - l];
    }
    void sort(vector<int>& a, int l, int r) {
        if (l >= r)
            return;
        int m = l + (r - l) / 2;
        sort(a, l, m);
        sort(a, m + 1, r);
        merge(a, l, m, r);
    }
    vector<int> sortArray(vector<int>& nums) {
        sort(nums, 0, nums.size() - 1);
        return nums;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna