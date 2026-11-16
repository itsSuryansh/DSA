class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
            return "0";
        string ans;
        if ((numerator < 0) ^ (denominator < 0))
            ans += "-";
        long long num = abs((long long)numerator);
        long long den = abs((long long)denominator);
        ans += to_string(num / den);
        long long rem = num % den;
        if (rem == 0)
            return ans;
        ans += ".";
        unordered_map<long long, int> mp;
        while (rem != 0) {
            if (mp.find(rem) != mp.end()) {
                ans.insert(mp[rem], "(");
                ans += ")";
                break;
            }
            mp[rem] = ans.size();
            rem *= 10;
            ans += to_string(rem / den);
            rem %= den;
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna