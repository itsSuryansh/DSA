class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        long long sum = 0;
        vector<pair<int, int>> gains;
        for (int num : nums) {
            string s = to_string(num);
            sort(s.begin(), s.end(), greater<char>());
            int rearranged = stoi(s);
            sum += num;
            gains.push_back({rearranged - num, rearranged});
        }
        sort(gains.rbegin(), gains.rend());
        for (int i = 0; i < min(k, (int)nums.size()); i++) {
            if (gains[i].first > 0) {
                sum += gains[i].first;
            }
        }
        return sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna