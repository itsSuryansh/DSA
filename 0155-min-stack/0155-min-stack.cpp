class MinStack {
    stack<int> st;
    stack<int> minSt;

public:
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
        
        if (minSt.empty())
            minSt.push(val);
        else
            minSt.push(min(val, minSt.top()));
    }
    
    void pop() {
        st.pop();
        minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna