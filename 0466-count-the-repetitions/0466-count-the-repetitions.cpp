class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int count = 0, j = 0;
        int m = s2.size();
        for (int i = 0; i < n1; i++) {
            for (char c : s1) {
                if (c == s2[j]) {
                    j++;
                    if (j == m) {
                        j = 0;
                        count++;
                    }
                }
            }
        }
        return count / n2;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna