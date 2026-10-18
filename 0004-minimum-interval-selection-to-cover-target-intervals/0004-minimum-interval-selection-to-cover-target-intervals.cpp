class Solution {
public:
    int minSelection(vector<vector<int>>& availableIntervals,
                     vector<vector<int>>& targetIntervals) {
        sort(availableIntervals.begin(), availableIntervals.end());
        sort(targetIntervals.begin(), targetIntervals.end());
        vector<vector<int>> targets;
        for (auto &t : targetIntervals) {
            if (targets.empty() || t[0] > targets.back()[1]) {
                targets.push_back(t);
            } else {
                targets.back()[1] = max(targets.back()[1], t[1]);
            }
        }
        priority_queue<int> pq;
        int i = 0, n = availableIntervals.size();
        int ans = 0;
        long long reach = LLONG_MIN;
        for (auto &t : targets) {
            long long L = t[0], R = t[1];
            while (reach < R) {
                long long x = max(L, reach);
                while (i < n && availableIntervals[i][0] <= x) {
                    pq.push(availableIntervals[i][1]);
                    i++;
                }
                while (!pq.empty() && pq.top() < x) {
                    pq.pop();
                }
                while (!pq.empty() && pq.top() == x && x < R) {
                    pq.pop();
                }
                if (pq.empty()) return -1;
                reach = pq.top();
                pq.pop();
                ans++;
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna