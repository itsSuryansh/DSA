class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int x = 0;
        for (int i : nums)
            x ^= i;
        return x == 0 || nums.size() % 2 == 0;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna