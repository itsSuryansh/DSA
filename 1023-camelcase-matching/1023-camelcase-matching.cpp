class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        for (string q : queries) {
            int i = 0, j = 0;
            bool ok = true;
            for (char c : q) {
                if (j < pattern.size() && c == pattern[j]) {
                    j++;
                } 
                else if (isupper(c)) {
                    ok = false;
                    break;
                }
            }
            if (j != pattern.size()) ok = false;
            ans.push_back(ok);
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna