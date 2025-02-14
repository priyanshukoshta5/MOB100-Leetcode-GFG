class ProductOfNumbers {
private:
    vector<int> nums;

public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        nums.push_back(num);
        return;
    }
    
    int getProduct(int k) {
        int res = 1;
        for(int i = nums.size() - 1; i >= 0 && k--; i--)
            res = res * nums[i];
        return res;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */