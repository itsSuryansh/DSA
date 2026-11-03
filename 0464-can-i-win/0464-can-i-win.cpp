class Solution {
public:
    vector<int> dp;
    bool solve(int mask, int t, int n) {
        if (dp[mask] != -1)
            return dp[mask];
        for (int i = 1; i <= n; i++) {
            if (!(mask & (1 << i))) {
                if (i >= t || !solve(mask | (1 << i), t - i, n))
                    return dp[mask] = 1;
            }
        }
        return dp[mask] = 0;
    }
    bool canIWin(int n, int t) {
        if (t <= 0)
            return true;
        if (n * (n + 1) / 2 < t)
            return false;
        dp.resize(1 << (n + 1), -1);
        return solve(0, t, n);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna