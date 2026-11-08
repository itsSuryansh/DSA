class Solution {
public:
    unordered_set<string> st;
    unordered_map<int, vector<string>> dp;
    vector<string> solve(int i, string &s) {
        if (i == s.size()) {
            return {""};
        }
        if (dp.count(i)) {
            return dp[i];
        }
        vector<string> ans;
        string word = "";
        for (int j = i; j < s.size(); j++) {
            word += s[j];
            if (st.count(word)) {
                vector<string> next = solve(j + 1, s);
                for (string &x : next) {
                    if (x == "")
                        ans.push_back(word);
                    else
                        ans.push_back(word + " " + x);
                }
            }
        }
        return dp[i] = ans;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (string &word : wordDict) {
            st.insert(word);
        }
        return solve(0, s);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna