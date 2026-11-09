class ProductOfNumbers {
public:
    vector<int> pref;
    ProductOfNumbers() {
        pref.push_back(1);
    }
    void add(int num) {
        if (num == 0) {
            pref.clear();
            pref.push_back(1);
        } else {
            pref.push_back(pref.back() * num);
        }
    }
    int getProduct(int k) {
        if (k >= pref.size()) return 0;
        return pref.back() / pref[pref.size() - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna