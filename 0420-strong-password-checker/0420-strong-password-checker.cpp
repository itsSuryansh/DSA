class Solution {
public:
    int strongPasswordChecker(string password) {
        int n = password.size();
        bool lower = false, upper = false, digit = false;
        for (char c : password) {
            if (islower(c)) lower = true;
            if (isupper(c)) upper = true;
            if (isdigit(c)) digit = true;
        }
        int missing = !lower + !upper + !digit;
        vector<int> groups;
        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && password[j] == password[i]) j++;
            if (j - i >= 3) {
                groups.push_back(j - i);
            }
            i = j;
        }
        if (n < 6) {
            return max(missing, 6 - n);
        }
        int replace = 0;
        for (int len : groups) {
            replace += len / 3;
        }
        if (n <= 20) {
            return max(missing, replace);
        }
        int remove = n - 20;
        int remaining = remove;
        for (int i = 0; i < groups.size() && remaining > 0; i++) {
            if (groups[i] % 3 == 0) {
                groups[i]--;
                replace--;
                remaining--;
            }
        }
        for (int i = 0; i < groups.size() && remaining > 0; i++) {
            while (groups[i] >= 3 && groups[i] % 3 == 1 && remaining >= 2) {
                groups[i] -= 2;
                replace--;
                remaining -= 2;
            }
        }
        for (int i = 0; i < groups.size() && remaining > 0; i++) {
            while (groups[i] >= 3 && remaining >= 3) {
                groups[i] -= 3;
                replace--;
                remaining -= 3;
            }
        }
        return remove + max(missing, replace);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna