class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> freq;
        string word;
        string s = s1 + " " + s2;
        for (char c : s) {
            if (c == ' ') {
                if (!word.empty()) {
                    freq[word]++;
                    word.clear();
                }
            } else {
                word += c;
            }
        }
        if (!word.empty())
            freq[word]++;
        vector<string> ans;
        for (auto& [word, count] : freq) {
            if (count == 1)
                ans.push_back(word);
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna