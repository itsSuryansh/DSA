class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int n = nums.size();
        int m = groups.size();
        int i = 0;
        for (int j = 0; j < m; j++) {
            int k = 0;
            bool ok = false;
            while (i < n) {
                if (nums[i] == groups[j][k]) {
                    int x = i, y = 0;
                    while (x < n && y < groups[j].size() &&
                           nums[x] == groups[j][y]) {
                        x++;
                        y++;
                    }
                    if (y == groups[j].size()) {
                        i = x;
                        ok = true;
                        break;
                    }
                }
                i++;
            }
            if (!ok) return false;
        }
        return true;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna