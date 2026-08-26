class MinStack {
private:
    stack<long long> st;
    long long minVal;

public:
    MinStack() {}

    void push(int x) {
        if (st.empty()) {
            st.push(x);
            minVal = x;
        }
        else if (x >= minVal) {
            st.push(x);
        }
        else {
            // Encode the previous minimum
            st.push(2LL * x - minVal);
            minVal = x;
        }
    }

    void pop() {
        if (st.empty())
            return;

        long long val = st.top();
        st.pop();

        // Encoded value means current minimum is being removed
        if (val < minVal) {
            // Recover previous minimum
            minVal = 2LL * minVal - val;
        }
    }

    int top() {
        long long val = st.top();

        if (val < minVal)
            return minVal;   // encoded value

        return val;
    }

    int getMin() {
        return minVal;
    }
};
