/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string s) {
        int i = 0;
        function<TreeNode*(int)> build = [&](int d) -> TreeNode* {
            int j = i, dep = 0;
            while (j < s.size() && s[j] == '-') {
                dep++;
                j++;
            }
            if (dep != d) return nullptr;
            i = j;
            int val = 0;
            while (i < s.size() && isdigit(s[i])) {
                val = val * 10 + (s[i] - '0');
                i++;
            }
            TreeNode* node = new TreeNode(val);
            node->left = build(d + 1);
            node->right = build(d + 1);
            return node;
        };
        return build(0);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna