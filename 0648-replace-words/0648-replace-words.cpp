class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        stringstream ss(sentence);
        string word, ans;
        while (ss >> word) {
            string prefix = "";
            for (char c : word) {
                prefix += c;
                if (st.count(prefix)) {
                    break;
                }
            }
            if (!ans.empty()) ans += " ";
            ans += prefix;
        }
        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna