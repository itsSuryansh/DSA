class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        for (char c : columnTitle) {
            ans = ans * 26 + (c - 'A' + 1);
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna