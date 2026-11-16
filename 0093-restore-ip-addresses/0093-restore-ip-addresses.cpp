class Solution {
public:
    vector<string> ans;
    void solve(string &s, int index, int parts, string ip) {
        if (parts == 4 && index == s.size()) {
            ip.pop_back();
            ans.push_back(ip);
            return;
        }
        if (parts >= 4 || index >= s.size())
            return;
        for (int len = 1; len <= 3 && index + len <= s.size(); len++) {
            string segment = s.substr(index, len);
            if (len > 1 && segment[0] == '0')
                continue;
            int num = stoi(segment);
            if (num > 255)
                continue;
            solve(s, index + len, parts + 1, ip + segment + ".");
        }
    }
    vector<string> restoreIpAddresses(string s) {
        if (s.size() < 4 || s.size() > 12)
            return {};
        solve(s, 0, 0, "");
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna