class Solution {
public:
    int mod = 1337;
    int mpow(int a, int b) {
        int r = 1;
        a %= mod;
        while (b > 0) {
            if (b % 2)
                r = (r * a) % mod;
            a = (a * a) % mod;
            b /= 2;
        }
        return r;
    }
    int superPow(int a, vector<int>& b) {
        int r = 1;
        for (int d : b) {
            r = (mpow(r, 10) * mpow(a, d)) % mod;
        }
        return r;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna