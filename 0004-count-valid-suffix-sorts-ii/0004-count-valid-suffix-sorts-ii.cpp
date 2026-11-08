class Solution {
public:
    vector<int> countSuffix(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        int m = target.size();
        const int MAXV = 100001;
        vector<int> s;
        for (int x : nums) s.push_back(x);
        s.push_back(-1);
        for (int x : target) s.push_back(x);
        int N = s.size();
        vector<int> z(N, 0);
        int l = 0, r = 0;
        for (int i = 1; i < N; i++) {
            if (i <= r)
                z[i] = min(r - i + 1, z[i - l]);
            while (i + z[i] < N &&
                   s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }
        vector<int> last(m, -1);
        for (int i = 1; i < m; i++) {
            last[i] = last[i - 1];

            if (target[i - 1] < target[i])
                last[i] = i - 1;
        }
        vector<int> freq(MAXV, 0);
        for (int x : nums)
            freq[x]++;
        for (int i = 0; i < n; i++)
            freq[target[i]]--;
        int different = 0;
        for (int x = 1; x < MAXV; x++) {
            if (freq[x] != 0)
                different++;
        }
        vector<int> ans(m - n + 1, 0);
        for (int k = 0; k <= m - n; k++) {
            if (different == 0) {
                int lcp = min(n, z[n + 1 + k]);
                int high = min(lcp, n - 1);
                int low = 0;
                int p = last[k + n - 1];
                if (p >= k)
                    low = p - k + 1;
                if (high >= low)
                    ans[k] = high - low + 1;
            }
            if (k < m - n) {
                int x = target[k];
                if (freq[x] == 0)
                    different++;
                freq[x]++;
                if (freq[x] == 0)
                    different--;
                int y = target[k + n];
                if (freq[y] == 0)
                    different++;
                freq[y]--;
                if (freq[y] == 0)
                    different--;
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna