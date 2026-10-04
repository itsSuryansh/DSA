class Solution {
public:
    int minRotations(string s) {
        int cur = 0;
        int ans = 0;
        for (char c : s) {
            int digit = c - '0';
            int diff = abs(cur - digit);
            ans += min(diff, 10 - diff);
            cur = digit;
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna