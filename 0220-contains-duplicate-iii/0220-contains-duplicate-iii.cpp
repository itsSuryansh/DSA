class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<long long> s;
        for (int i = 0; i < nums.size(); i++) {
            long long x = nums[i];
            auto it = s.lower_bound(x - valueDiff);
            if (it != s.end() && *it <= x + valueDiff)
                return true;
            s.insert(x);
            if (s.size() > indexDiff)
                s.erase(nums[i - indexDiff]);
        }
        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna