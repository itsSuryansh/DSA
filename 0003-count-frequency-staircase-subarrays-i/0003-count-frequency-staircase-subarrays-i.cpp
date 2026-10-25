class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size();
        int maxK = 0;
        while (1LL * (maxK + 1) * (maxK + 2) / 2 <= n) {
            maxK++;
        }
        int ans = 0;
        for (int l = 0; l < n; l++) {
            unordered_map<int, int> rank, freq;
            int distinct = 0;
            int matched = 0;
            for (int r = l; r < n; r++) {
                int x = nums[r];
                if (!rank.count(x)) {
                    if (distinct == maxK) break;
                    rank[x] = ++distinct;
                }
                int k = rank[x];
                if (freq[x] == k) matched--;
                freq[x]++;
                if (freq[x] > k) break;
                if (freq[x] == k) matched++;
                if (matched == distinct) ans++;
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna