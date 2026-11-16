class Solution {
public:
    bool isValidSerialization(string preorder) {
        int slots = 1;
        stringstream ss(preorder);
        string node;
        while (getline(ss, node, ',')) {
            if (slots == 0)
                return false;
            slots--;
            if (node != "#")
                slots += 2;
        }
        return slots == 0;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna