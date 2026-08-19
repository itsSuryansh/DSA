class Solution {
public:
    int strStr(string s, string p) {
        int n = s.size();
        int m = p.size();
        for (int i = 0; i <= n - m; i++) {
            int j = 0;
            while (j < m && s[i + j] == p[j]) {
                j++;
            }
            if (j == m)
                return i;
        }
        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna