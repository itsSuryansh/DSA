
class Solution {
public:
    long long minCost(int n, string colors,
                      vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> parent(n, -1);
        vector<int> order = {0};

        // Build traversal order
        for (int i = 0; i < n; i++) {
            int u = order[i];

            for (int v : adj[u]) {
                if (v == parent[u]) continue;

                parent[v] = u;
                order.push_back(v);
            }
        }

        // Calculate subtree sizes
        vector<long long> sz(n, 1);

        for (int i = n - 1; i > 0; i--) {
            int u = order[i];
            sz[parent[u]] += sz[u];
        }

        long long baseCost = 0;

        for (int i = 0; i < n; i++) {
            if (colors[i] == 'R')
                baseCost += sz[i];
        }

        // Tree DP
        vector<long long> dp(n, 0);
        long long best = 0;

        for (int i = n - 1; i >= 0; i--) {
            int u = order[i];

            if (colors[u] == 'R')
                dp[u] = sz[u];
            else
                dp[u] = -sz[u];

            for (int v : adj[u]) {
                if (parent[v] == u) {
                    dp[u] += max(0LL, dp[v]);
                }
            }

            best = max(best, dp[u]);
        }

        return baseCost - best;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna