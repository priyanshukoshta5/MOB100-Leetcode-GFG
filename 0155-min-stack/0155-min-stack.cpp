class MinStack {
public:
    stack<pair<int,int>> st;  // {element, min_val_till_now}
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty())
            st.push({val, val});
        else
        {
            int curmin = min(val, st.top().second);
            st.push({val, curmin});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
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