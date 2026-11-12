class Solution {
public:
    struct DSU {
        vector<int> parent, sz;

        DSU(int n) {
            parent.resize(n);
            sz.assign(n, 1);
            iota(parent.begin(), parent.end(), 0);
        }

        int find(int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }

        bool unite(int a, int b) {
            a = find(a);
            b = find(b);

            if (a == b) return false;

            if (sz[a] < sz[b])
                swap(a, b);

            parent[b] = a;
            sz[a] += sz[b];

            return true;
        }
    };

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(
        int n, vector<vector<int>>& edges) {

        int m = edges.size();

        vector<array<int, 4>> e;

        for (int i = 0; i < m; i++) {
            e.push_back({edges[i][0], edges[i][1], edges[i][2], i});
        }

        sort(e.begin(), e.end(), [](auto& a, auto& b) {
            return a[2] < b[2];
        });

        auto mst = [&](int skip, int force) {
            DSU dsu(n);
            int cost = 0, count = 0;

            if (force != -1) {
                auto x = e[force];
                dsu.unite(x[0], x[1]);
                cost += x[2];
                count++;
            }

            for (int i = 0; i < m; i++) {
                if (i == skip || i == force) continue;

                if (dsu.unite(e[i][0], e[i][1])) {
                    cost += e[i][2];
                    count++;
                }
            }

            return count == n - 1 ? cost : INT_MAX;
        };

        int base = mst(-1, -1);

        vector<int> critical, pseudo;

        for (int i = 0; i < m; i++) {
            if (mst(i, -1) > base) {
                critical.push_back(e[i][3]);
            }
            else if (mst(-1, i) == base) {
                pseudo.push_back(e[i][3]);
            }
        }

        return {critical, pseudo};
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna