class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<int> st;

        int prev = 0;

        for (string &log : logs) {
            stringstream ss(log);
            string id, type, time;

            getline(ss, id, ':');
            getline(ss, type, ':');
            getline(ss, time, ':');

            int fid = stoi(id);
            int t = stoi(time);

            if (type == "start") {
                if (!st.empty()) {
                    ans[st.top()] += t - prev;
                }

                st.push(fid);
                prev = t;
            }
            else {
                ans[st.top()] += t - prev + 1;
                st.pop();
                prev = t + 1;
            }
        }

        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna