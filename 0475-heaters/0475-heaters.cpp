class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int ans = 0;
        for (int house : houses) {
            int left = 0, right = heaters.size() - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (heaters[mid] < house)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            int leftDist = INT_MAX;
            int rightDist = INT_MAX;
            if (right >= 0)
                leftDist = house - heaters[right];
            if (left < heaters.size())
                rightDist = heaters[left] - house;
            ans = max(ans, min(leftDist, rightDist));
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna