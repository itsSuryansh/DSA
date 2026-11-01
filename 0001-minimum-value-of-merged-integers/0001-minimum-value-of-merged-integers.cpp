class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        long long ans = LLONG_MAX;
        for (int i = 0; i < nums.size(); i += 2) {
            long long a = nums[i];
            long long b = nums[i + 1];
            long long multiplier = 10;
            while (multiplier <= b) {
                multiplier *= 10;
            }
            long long merged = a * multiplier + b;
            ans = min(ans, merged);
        }
        return (int)ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna