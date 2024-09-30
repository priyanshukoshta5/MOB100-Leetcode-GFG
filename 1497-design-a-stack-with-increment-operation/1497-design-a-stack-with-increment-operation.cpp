class CustomStack {
private:
    int size;
    stack<int> stk;

public:
    CustomStack(int maxSize) {
        size = maxSize;
    }
    
    void push(int x) {
        if(stk.size() < size)
            stk.push(x);
        return;
    }
    
    int pop() {
        if(stk.size() == 0)
            return -1;
        int val = stk.top();
        stk.pop();
        return val;
    }
    
    void increment(int k, int val) {
        vector<int> arr;
        while(!stk.empty())
        {
            arr.push_back(stk.top());
            stk.pop();
        }
        int n = arr.size();
        for(int i = 1; i <= k && (n - i) >= 0; i++)
            arr[n - i] += val;
        
        for(int i = n - 1; i >= 0; i--)
            stk.push(arr[i]);
        
        return;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */