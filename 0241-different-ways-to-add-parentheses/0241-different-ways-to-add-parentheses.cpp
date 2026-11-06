class Solution {
public:
    unordered_map<string, vector<int>> dp;
    vector<int> diffWaysToCompute(string expression) {
        if (dp.count(expression)) {
            return dp[expression];
        }
        vector<int> ans;
        for (int i = 0; i < expression.size(); i++) {
            char ch = expression[i];
            if (ch == '+' || ch == '-' || ch == '*') {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));
                for (int a : left) {
                    for (int b : right) {
                        if (ch == '+')
                            ans.push_back(a + b);
                        else if (ch == '-')
                            ans.push_back(a - b);
                        else
                            ans.push_back(a * b);
                    }
                }
            }
        }
        if (ans.empty()) {
            ans.push_back(stoi(expression));
        }
        return dp[expression] = ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna