class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        function<void(int)> backtrack = [&](int index) {
            ans.push_back(curr);
            for (int i = index; i < nums.size(); i++) {
                curr.push_back(nums[i]);
                backtrack(i + 1);
                curr.pop_back();
            }
        };
        backtrack(0);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna