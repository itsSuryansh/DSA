class Solution {
public:
    vector<int> seg, prev;
    int n;
    void build(vector<int>& nums, int node, int l, int r) {
        if (l == r) {
            seg[node] = nums[l];
            return;
        }
        int mid = (l + r) / 2;
        build(nums, node * 2, l, mid);
        build(nums, node * 2 + 1, mid + 1, r);
        seg[node] = seg[node * 2] & seg[node * 2 + 1];
    }
    int findLast(int node, int l, int r, int ql, int qr, int m) {
        if (r < ql || l > qr || (seg[node] & m) == m)
            return -1;
        if (l == r)
            return l;
        int mid = (l + r) / 2;
        int res = findLast(node * 2 + 1, mid + 1, r, ql, qr, m);
        if (res == -1)
            res = findLast(node * 2, l, mid, ql, qr, m);
        return res;
    }
    int findFirst(int node, int l, int r, int ql, int qr, int m) {
        if (r < ql || l > qr || (seg[node] & m) == m)
            return -1;
        if (l == r)
            return l;
        int mid = (l + r) / 2;
        int res = findFirst(node * 2, l, mid, ql, qr, m);
        if (res == -1)
            res = findFirst(node * 2 + 1, mid + 1, r, ql, qr, m);
        return res;
    }
    long long countConsistent(vector<int>& nums) {
        n = nums.size();
        seg.resize(4 * n);
        build(nums, 1, 0, n - 1);
        prev.resize(n);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && nums[s.top()] > nums[i])
                s.pop();
            prev[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int m = nums[i];
            int leftBad = findLast(1, 0, n - 1, 0, i - 1, m);
            int rightBad = findFirst(1, 0, n - 1, i + 1, n - 1, m);
            int L = max(leftBad + 1, prev[i] + 1);
            int R = rightBad == -1 ? n - 1 : rightBad - 1;
            ans += 1LL * (i - L + 1) * (R - i + 1);
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna