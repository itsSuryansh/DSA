
class Solution {
public:
    int longestString(int x, int y, int z) {

        int pairs = 2 * min(x, y);

        int extra = (x != y) ? 1 : 0;

        int total = pairs + extra + z;

        return total * 2;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna