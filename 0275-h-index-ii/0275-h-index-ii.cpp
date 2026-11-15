class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int low = 0, high = n;
        while (low < high) {
            int mid = low + (high - low) / 2;

            if (citations[mid] >= n - mid) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return n - low;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna