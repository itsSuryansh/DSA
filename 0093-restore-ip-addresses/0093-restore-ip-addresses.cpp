class Solution {
public:
    vector<string> ans;
    vector<string> path;
    void backtrack(string& s, int index) {
            if (path.size() == 4) {
            if (index == s.size()) {
                ans.push_back(
                    path[0] + "." +
                    path[1] + "." +
                    path[2] + "." +
                    path[3]
                );
            }
            return;
        }
        int num = 0;
        for (int i = index; i < s.size() && i < index + 3; i++) {
            if (i > index && s[index] == '0')
                break;
            num = num * 10 + (s[i] - '0');
            if (num > 255)
                break;
            path.push_back(s.substr(index, i - index + 1));
            backtrack(s, i + 1);
            path.pop_back(); // backtrack
        }
    }
    vector<string> restoreIpAddresses(string s) {
        backtrack(s, 0);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna