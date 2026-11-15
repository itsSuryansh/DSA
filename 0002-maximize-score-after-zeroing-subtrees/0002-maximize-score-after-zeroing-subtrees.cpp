class Solution {
public:
    int maxScore(vector<int>& parent, vector<int>& op, vector<int>& score) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }
        vector<int> order;
        stack<int> st;
        st.push(0);
        while (!st.empty()) {
            int u = st.top();
            st.pop();
            order.push_back(u);
            for (int v : adj[u]) {
                st.push(v);
            }
        }
        vector<long long> dp(n);
        for (int i = n - 1; i >= 0; i--) {
            int u = order[i];
            long long sum = score[u];
            long long mn = LLONG_MAX;
            for (int v : adj[u]) {
                sum += dp[v];
                mn = min(mn, dp[v]);
            }
            if (mn != LLONG_MAX) {
                if (op[u] == 1)
                    sum -= mn;
                else if (mn < 0)
                    sum -= mn;
            }
            dp[u] = sum;
        }
        return (int)dp[0];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna