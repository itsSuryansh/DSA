class Solution {
public:
    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        long long ab = lcm(a, b);
        long long ac = lcm(a, c);
        long long bc = lcm(b, c);
        long long abc = lcm(ab, c);
        long long lo = 1, hi = 2000000000LL;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            long long cnt = mid / a + mid / b + mid / c
                          - mid / ab - mid / ac - mid / bc
                          + mid / abc;
            if (cnt >= n)
                hi = mid;
            else
                lo = mid + 1;
        }
        return (int)lo;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna