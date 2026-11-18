
class Solution {
public:
    vector<vector<string>> findLadders(
        string beginWord,
        string endWord,
        vector<string>& wordList
    ) {
        unordered_set<string> dict(wordList.begin(), wordList.end());

        vector<vector<string>> ans;

        if (!dict.count(endWord)) {
            return ans;
        }

        unordered_map<string, vector<string>> parent;

        queue<string> q;
        q.push(beginWord);

        unordered_set<string> visited;
        visited.insert(beginWord);

        bool found = false;

        // BFS
        while (!q.empty() && !found) {

            int size = q.size();

            unordered_set<string> levelVisited;

            for (int i = 0; i < size; i++) {

                string word = q.front();
                q.pop();

                for (int j = 0; j < word.size(); j++) {

                    string temp = word;

                    for (char ch = 'a'; ch <= 'z'; ch++) {

                        if (temp[j] == ch)
                            continue;

                        temp[j] = ch;

                        if (dict.count(temp) && !visited.count(temp)) {

                            if (temp == endWord)
                                found = true;

                            parent[temp].push_back(word);

                            if (!levelVisited.count(temp)) {
                                q.push(temp);
                                levelVisited.insert(temp);
                            }
                        }
                    }
                }
            }

            // Mark all words of current level as visited
            for (auto& word : levelVisited) {
                visited.insert(word);
            }
        }

        // Backtracking
        if (found) {
            vector<string> path;
            path.push_back(endWord);

            dfs(endWord, beginWord, parent, path, ans);
        }

        return ans;
    }

    void dfs(
        string word,
        string beginWord,
        unordered_map<string, vector<string>>& parent,
        vector<string>& path,
        vector<vector<string>>& ans
    ) {

        if (word == beginWord) {

            vector<string> temp = path;
            reverse(temp.begin(), temp.end());

            ans.push_back(temp);
            return;
        }

        for (string p : parent[word]) {

            path.push_back(p);

            dfs(p, beginWord, parent, path, ans);

            path.pop_back();
        }
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna