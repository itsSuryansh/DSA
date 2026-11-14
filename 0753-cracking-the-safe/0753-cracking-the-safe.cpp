class Solution {
public:
    string crackSafe(int n, int k) {
        unordered_set<string> visited;
        string ans;
        string start(n - 1, '0');
        function<void(string)> dfs = [&](string node) {
            for (int i = 0; i < k; i++) {
                string edge = node + char('0' + i);
                if (visited.insert(edge).second) {
                    dfs(edge.substr(1));
                    ans += char('0' + i);
                }
            }
        };
        dfs(start);
        ans += start;
        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna