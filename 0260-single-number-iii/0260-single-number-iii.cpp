class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int XOR = 0;
        for (int num : nums) {
            XOR ^= static_cast<unsigned int>(num);
        }
        unsigned int bit = XOR & (~XOR + 1);
        int a = 0, b = 0;
        for (int num : nums) {
            if (static_cast<unsigned int>(num) & bit) {
                a ^= num;
            }
            else {
                b ^= num;
            }
        }
        return {a, b};
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna