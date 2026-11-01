class Solution {
public:
    long long minimumMaxValue(int n, int index, int value) {
        if (value == 1) {
            return -1;
        }
        int p = value;
        for (int i = 2; i * i <= value; i++) {
            if (value % i == 0) {
                p = i;
                break;
            }
        }
        int left = (value - p) / 2;
        if (index > left) {
            return -1;
        }
        int right = n - index - 1;
        long long ans = value;
        if (right > 0) {
            ans = (long long)value + p + 2LL * (right - 1);
        }
        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna