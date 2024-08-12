class KthLargest {
private:
    int K;
    priority_queue<int, vector<int>, greater<int>> minH;

public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(auto i: nums)
            add(i);
    }
    
    int add(int val) {
        minH.push(val);
        if(minH.size() > K)
            minH.pop();
        return minH.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */