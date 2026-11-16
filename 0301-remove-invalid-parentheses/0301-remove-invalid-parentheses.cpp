class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        unordered_set<string> visited;
        queue<string> q;
        q.push(s);
        visited.insert(s);
        bool found = false;
        while (!q.empty()) {
            string str = q.front();
            q.pop();
            if (isValid(str)) {
                ans.push_back(str);
                found = true;
            }
            if (found)
                continue;
            for (int i = 0; i < str.size(); i++) {
                if (str[i] != '(' && str[i] != ')')
                    continue;
                string next = str.substr(0, i) + str.substr(i + 1);
                if (!visited.count(next)) {
                    q.push(next);
                    visited.insert(next);
                }
            }
        }
        return ans;
    }
    bool isValid(string s) {
        int count = 0;
        for (char ch : s) {
            if (ch == '(')
                count++;
            else if (ch == ')') {
                count--;
                if (count < 0)
                    return false;
            }
        }
        return count == 0;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna