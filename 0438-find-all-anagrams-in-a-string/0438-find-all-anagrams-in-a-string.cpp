class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.size(), m = p.size();
        if (m > n) return ans;
        vector<int> count1(26, 0), count2(26, 0);
        for (int i = 0; i < m; i++) {
            count1[p[i] - 'a']++;
            count2[s[i] - 'a']++;
        }
        if (count1 == count2) ans.push_back(0);
        for (int i = m; i < n; i++) {
            count2[s[i] - 'a']++;
            count2[s[i - m] - 'a']--;
            if (count1 == count2) {
                ans.push_back(i - m + 1);
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna