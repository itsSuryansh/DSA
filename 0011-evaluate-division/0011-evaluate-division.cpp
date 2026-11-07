class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> adj;
    double dfs(string src, string dest, unordered_set<string>& visited) {
        if (!adj.count(src) || !adj.count(dest)) return -1.0;
        if (src == dest) return 1.0;
        visited.insert(src);
        for (auto &[next, weight] : adj[src]) {
            if (visited.count(next)) continue;
            double result = dfs(next, dest, visited);
            if (result != -1.0) {
                return weight * result;
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(
        vector<vector<string>>& equations,
        vector<double>& values,
        vector<vector<string>>& queries
    ) {
        for (int i = 0; i < equations.size(); i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            adj[u].push_back({v, values[i]});
            adj[v].push_back({u, 1.0 / values[i]});
        }
        vector<double> ans;
        for (auto &q : queries) {
            unordered_set<string> visited;
            ans.push_back(dfs(q[0], q[1], visited));
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna