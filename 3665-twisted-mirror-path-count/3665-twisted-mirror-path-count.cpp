class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int mod = 1e9 + 7;
        int r = grid.size(), c = grid[0].size();
        auto arr = grid;
        vector<vector<vector<long long>>> ways(r, vector<vector<long long>>(c, vector<long long>(2, 0)));
        ways[0][0][0] = 1;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                for (int k = 0; k < 2; k++) {
                    long long cnt = ways[i][j][k];
                    if (cnt == 0) continue;
                    if (arr[i][j] == 0) {
                        if (j + 1 < c) ways[i][j + 1][0] = (ways[i][j + 1][0] + cnt) % mod;
                        if (i + 1 < r) ways[i + 1][j][1] = (ways[i + 1][j][1] + cnt) % mod;
                    } else {
                        if (k == 0 && i + 1 < r) ways[i + 1][j][1] = (ways[i + 1][j][1] + cnt) % mod;
                        else if (k == 1 && j + 1 < c) ways[i][j + 1][0] = (ways[i][j + 1][0] + cnt) % mod;
                    }
                }
            }
        }
        return (ways[r - 1][c - 1][0] + ways[r - 1][c - 1][1]) % mod;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna