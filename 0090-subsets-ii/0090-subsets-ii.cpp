
class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums, int idx, vector<int>& temp) {
        ans.push_back(temp);

        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i] == nums[i - 1])
                continue;

            temp.push_back(nums[i]);

            solve(nums, i + 1, temp);

            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> temp;

        solve(nums, 0, temp);

        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna