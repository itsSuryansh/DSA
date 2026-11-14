class Codec {
public:
    void preorder(TreeNode* root, string& s) {
        if (!root) return;
        s += to_string(root->val) + ",";
        preorder(root->left, s);
        preorder(root->right, s);
    }
    string serialize(TreeNode* root) {
        string s;
        preorder(root, s);
        return s;
    }
    TreeNode* build(vector<int>& nums, int& i, long long low, long long high) {
        if (i >= nums.size() || nums[i] <= low || nums[i] >= high)
            return NULL;
        TreeNode* root = new TreeNode(nums[i++]);
        root->left = build(nums, i, low, root->val);
        root->right = build(nums, i, root->val, high);
        return root;
    }
    TreeNode* deserialize(string data) {
        vector<int> nums;
        stringstream ss(data);
        string x;
        while (getline(ss, x, ',')) {
            if (!x.empty()) nums.push_back(stoi(x));
        }
        int i = 0;
        return build(nums, i, LLONG_MIN, LLONG_MAX);
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna