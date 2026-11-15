class Solution {
public:
    long long maxDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long> dp(n + 2, 0);
        for (int i = n - 1; i >= 0; i--) {
            long long one = nums[i];
            if (nums[i] % 3 == 0)
                one -= dp[i + 1];
            else
                one += dp[i + 1];
            dp[i] = one;
            if (i + 1 < n) {
                long long two = nums[i] + nums[i + 1];
                if (two % 3 == 0)
                    two -= dp[i + 2];
                else
                    two += dp[i + 2];
                dp[i] = max(dp[i], two);
            }
        }
        return dp[0];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna