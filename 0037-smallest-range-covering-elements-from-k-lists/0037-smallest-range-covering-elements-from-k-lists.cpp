class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        using T = tuple<int, int, int>;

        priority_queue<T, vector<T>, greater<T>> pq;

        int maxi = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i][0], i, 0});
            maxi = max(maxi, nums[i][0]);
        }

        int l = 0, r = INT_MAX;

        while (pq.size() == nums.size()) {
            auto [mini, row, col] = pq.top();
            pq.pop();

            if (maxi - mini < r - l) {
                l = mini;
                r = maxi;
            }

            if (col + 1 == nums[row].size())
                break;

            int next = nums[row][col + 1];

            maxi = max(maxi, next);

            pq.push({next, row, col + 1});
        }

        return {l, r};
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna