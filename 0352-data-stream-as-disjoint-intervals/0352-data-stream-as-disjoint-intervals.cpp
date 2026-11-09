class SummaryRanges {
public:
    map<int, int> mp;
    SummaryRanges() {
    }
    void addNum(int value) {
        auto it = mp.upper_bound(value);
        int start = value, end = value;
        if (it != mp.begin()) {
            auto prev = std::prev(it);
            if (prev->second >= value) return;
            if (prev->second + 1 == value) {
                start = prev->first;
                mp.erase(prev);
            }
        }
        if (it != mp.end() && it->first == value + 1) {
            end = it->second;
            mp.erase(it);
        }
        mp[start] = end;
    }
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for (auto &it : mp) {
            ans.push_back({it.first, it.second});
        }
        return ans;
    }
};
/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna