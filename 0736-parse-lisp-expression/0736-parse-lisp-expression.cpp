
class Solution {
public:
    int evaluate(string expression) {
        unordered_map<string, vector<int>> mp;

        function<int(int&)> parse = [&](int& i) -> int {
            while (i < expression.size() && expression[i] == ' ') i++;

            if (expression[i] == '(') {
                i++;

                while (expression[i] == ' ') i++;

                string op;
                while (isalpha(expression[i])) {
                    op += expression[i++];
                }

                int ans = 0;

                if (op == "add" || op == "mult") {
                    int a = parse(i);
                    int b = parse(i);

                    ans = (op == "add") ? a + b : a * b;
                }
                else {
                    vector<string> vars;

                    while (true) {
                        while (expression[i] == ' ') i++;

                        if (expression[i] == '(' || 
                            expression[i] == '-' || 
                            isdigit(expression[i])) {
                            ans = parse(i);
                            break;
                        }

                        string var;
                        while (isalnum(expression[i])) {
                            var += expression[i++];
                        }

                        while (expression[i] == ' ') i++;

                        if (expression[i] == ')') {
                            ans = mp[var].back();
                            break;
                        }
                        int val = parse(i);
                        mp[var].push_back(val);
                        vars.push_back(var);
                    }
                    for (string var : vars) {
                        mp[var].pop_back();
                    }
                }
                i++;
                return ans;
            }
            if (expression[i] == '-') {
                i++;
                int num = 0;
                while (isdigit(expression[i])) {
                    num = num * 10 + expression[i++] - '0';
                }
                return -num;
            }
            if (isdigit(expression[i])) {
                int num = 0;
                while (isdigit(expression[i])) {
                    num = num * 10 + expression[i++] - '0';
                }
                return num;
            }
            string var;
            while (isalnum(expression[i])) {
                var += expression[i++];
            }
            return mp[var].back();
        };
        int i = 0;
        return parse(i);
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna