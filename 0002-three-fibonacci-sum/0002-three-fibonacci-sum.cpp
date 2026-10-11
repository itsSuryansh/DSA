
class Solution {
public:
    bool threeFibonacciSum(int n) {
        long long a = 0, b = 1;
        while (true) {
            long long c = a + b;
            long long sum = a + b + c;
            if (sum == n)
                return true;
            if (sum > n)
                return false;
            a = b;
            b = c;
        }
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna