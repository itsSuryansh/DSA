class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
                sort(people.begin(), people.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] == b[0])
                     return a[1] < b[1];
                 return a[0] > b[0];
             });
        vector<vector<int>> ans;
        for (auto& person : people) {
            ans.insert(ans.begin() + person[1], person);
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna