class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int mod = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();
        auto vornadexil = grid;
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(2, 0)));
        dp[0][0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int d = 0; d < 2; d++) {
                    long long ways = dp[i][j][d];
                    if (ways == 0) continue;
                    if (vornadexil[i][j] == 0) {
                        if (j + 1 < n) dp[i][j + 1][0] = (dp[i][j + 1][0] + ways) % mod;
                        if (i + 1 < m) dp[i + 1][j][1] = (dp[i + 1][j][1] + ways) % mod;
                    } else {
                        if (d == 0 && i + 1 < m) dp[i + 1][j][1] = (dp[i + 1][j][1] + ways) % mod;
                        else if (d == 1 && j + 1 < n) dp[i][j + 1][0] = (dp[i][j + 1][0] + ways) % mod;
                    }
                }
            }
        }
        return (dp[m - 1][n - 1][0] + dp[m - 1][n - 1][1]) % mod;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna