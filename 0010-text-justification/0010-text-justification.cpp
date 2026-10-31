class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        int i = 0;
        while (i < n) {
            int j = i;
            int len = 0;
            while (j < n && len + words[j].size() + (j - i) <= maxWidth) {
                len += words[j].size();
                j++;
            }
            int cnt = j - i;
            int spaces = maxWidth - len;
            string line;
            if (j == n || cnt == 1) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k != j - 1)
                        line += " ";
                }
                line += string(maxWidth - line.size(), ' ');
            }
            else {
                int gap = spaces / (cnt - 1);
                int extra = spaces % (cnt - 1);
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k != j - 1) {
                        int s = gap + (extra > 0 ? 1 : 0);
                        line += string(s, ' ');
                        if (extra > 0)
                            extra--;
                    }
                }
            }
            ans.push_back(line);
            i = j;
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna