class MinStack {
public:
    MinStack() {
    }
    stack<int> st;
    stack<int> minStack;

    void push(int val) {
        st.push(val);
        
        if(minStack.empty()) {
            minStack.push(val);
        }
        else {
            int cur = min(val, minStack.top());
            minStack.push(cur);
        }
    }
    
    void pop() {
        minStack.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
