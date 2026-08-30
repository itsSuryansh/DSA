class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        function<void(int, int)> backtrack = [&](int start, int remaining) {
            if (remaining == 0) {
                ans.push_back(curr);
                return;
            }
            for (int i = start; i < candidates.size(); i++) {
                if (candidates[i] > remaining)
                    continue;
                curr.push_back(candidates[i]);
                backtrack(i, remaining - candidates[i]);
                curr.pop_back();
            }
        };
        backtrack(0, target);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna