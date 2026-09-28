class Solution {
public:
    int sum = 0;
    bool isHappy(int n) {
        set<int> s;
        while (n != 1) {
            if (s.count(n))
                return false;
            s.insert(n);
            sum = 0;
            while (n > 0) {
                int digit = n % 10;
                sum += digit * digit;
                n = n / 10;
            }
            n = sum;
        }
        return true;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna