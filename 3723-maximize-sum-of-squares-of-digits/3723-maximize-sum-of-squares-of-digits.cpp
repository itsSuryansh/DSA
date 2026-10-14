class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) {
            return "";
        }
        string ans = "";
        int nines = sum / 9;
        int remainder = sum % 9;
        ans.append(nines, '9');
        if (remainder > 0) {
            ans += to_string(remainder);
        }
        while (ans.size() < num) {
            ans += '0';
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna