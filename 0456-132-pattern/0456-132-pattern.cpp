class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        int mid = INT_MIN;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] < mid)
                return true;
            while (!st.empty() && st.top() < nums[i]) {
                mid = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna