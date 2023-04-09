class MinStack {
public:
    stack<long long> st;
    long long mini;

    MinStack() {
        mini = INT_MAX;
    }
    
    void push(int val) {
        long long el = val;
        if(st.empty())
        {
            st.push(el);
            mini = el;
        }
        else
        {
            if(el < mini)
            {
                st.push(el*2 - mini);
                mini = el;
            }
            else
               st.push(el);
        }
    }
    
    void pop() {
        if(st.empty())
            return;
        long long el = st.top();
        st.pop();
        if(el < mini)
            mini = 2*mini - el;
    }
    
    int top() {
        if(st.empty())
            return -1;
        long long el = st.top();
        if(el < mini)
            return mini;
        return el;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */