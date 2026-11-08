
class Solution {
public:
    int dp[100][100][100];

    int solve(vector<int>& boxes, int l, int r, int k) {
        if (l > r)
            return 0;

        // Compress consecutive equal boxes from the right
        while (l < r && boxes[r] == boxes[r - 1]) {
            r--;
            k++;
        }

        // Check memo AFTER normalization
        if (dp[l][r][k] != -1)
            return dp[l][r][k];

        // Option 1: Remove the rightmost group now
        int ans = solve(boxes, l, r - 1, 0)
                  + (k + 1) * (k + 1);

        // Option 2: Merge with an earlier group of same color
        for (int i = l; i < r; i++) {
            if (boxes[i] == boxes[r]) {

                ans = max(ans,
                    solve(boxes, l, i, k + 1) +
                    solve(boxes, i + 1, r - 1, 0)
                );
            }
        }

        return dp[l][r][k] = ans;
    }

    int removeBoxes(vector<int>& boxes) {
        memset(dp, -1, sizeof(dp));

        return solve(boxes, 0, boxes.size() - 1, 0);
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna