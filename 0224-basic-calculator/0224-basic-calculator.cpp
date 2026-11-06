class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        long long result = 0;
        long long number = 0;
        long long sign = 1;
        for (char ch : s) {
            if (isdigit(ch)) {
                number = number * 10 + (ch - '0');
            }
            else if (ch == '+') {
                result += sign * number;
                number = 0;
                sign = 1;
            }
            else if (ch == '-') {
                result += sign * number;
                number = 0;
                sign = -1;
            }
            else if (ch == '(') {
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            }
            else if (ch == ')') {
                result += sign * number;
                number = 0;
                result *= st.top();
                st.pop();
                result += st.top();
                st.pop();
            }
        }
        return result + sign * number;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna