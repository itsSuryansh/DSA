class Solution {
public:
    int magicalString(int n) {
        if (n <= 0) return 0;

        vector<int> s(n + 1, 0);
        s[0] = 1;

        if (n == 1) return 1;

        s[1] = 2;

        if (n == 2) return 1;

        s[2] = 2;

        int head = 2, tail = 3;
        int num = 1, ans = 1;

        while (tail < n) {
            int cnt = s[head];

            while (cnt-- && tail < n) {
                s[tail] = num;

                if (num == 1)
                    ans++;

                tail++;
            }

            num = 3 - num;
            head++;
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna