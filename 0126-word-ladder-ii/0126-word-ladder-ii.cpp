
class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> parent;

    void dfs(string word, string beginWord, vector<string>& path) {
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        for (string p : parent[word]) {
            path.push_back(p);
            dfs(p, beginWord, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        ans.clear();
        parent.clear();

        unordered_set<string> st(wordList.begin(), wordList.end());

        if (!st.count(endWord))
            return ans;

        queue<string> q;
        q.push(beginWord);
        st.erase(beginWord);

        bool found = false;

        while (!q.empty() && !found) {
            int size = q.size();
            unordered_set<string> used;

            while (size--) {
                string word = q.front();
                q.pop();

                string temp = word;

                for (int i = 0; i < word.size(); i++) {
                    char original = temp[i];

                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        if (ch == original)
                            continue;

                        temp[i] = ch;

                        if (st.count(temp)) {
                            parent[temp].push_back(word);
                            used.insert(temp);

                            if (temp == endWord)
                                found = true;
                        }
                    }

                    temp[i] = original;
                }
            }

            for (string word : used) {
                q.push(word);
                st.erase(word);
            }
        }

        if (!found)
            return ans;

        vector<string> path = {endWord};
        dfs(endWord, beginWord, path);

        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna