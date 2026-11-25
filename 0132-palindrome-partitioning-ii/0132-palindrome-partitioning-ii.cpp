class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        vector<int> cuts(n);

        for (int i = n - 1; i >= 0; i--) {
            cuts[i] = n - i - 1;

            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;

                    if (j == n - 1)
                        cuts[i] = 0;
                    else
                        cuts[i] = min(cuts[i], 1 + cuts[j + 1]);
                }
            }
        }

        return cuts[0];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna