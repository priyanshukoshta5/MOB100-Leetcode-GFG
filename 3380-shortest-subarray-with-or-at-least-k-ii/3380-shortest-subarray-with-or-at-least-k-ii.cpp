class Solution {
private:
    bool isBitPresent(int num, int b){
        return ((num >> b) & 1) == 1;
    }

    void addBitNum(int num, vector<int> &bitAvl){
        for(int i = 0; i < 32; i++)
        {
            if(isBitPresent(num, i))
                bitAvl[i]++;
        }
        return;
    }

    void delBitNum(int num, vector<int> &bitAvl){
        for(int i = 0; i < 32; i++)
        {
            if(isBitPresent(num, i))
                bitAvl[i]--;
        }
        return;
    }

    long long getNum(vector<int> &bitAvl){
        long long num = 0;
        for(int i = 0; i < 32; i++)
        {
            if(bitAvl[i] > 0)
                num = num | (1 << i);
        }
        return num;
    }
    
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == 0)
            return 1;
        
        vector<int> bitAvl(32, 0);
        int ans = INT_MAX;
        int i = 0, j = 0;
        while(j < n)
        {
            addBitNum(nums[j], bitAvl);
            while(getNum(bitAvl) >= k)
            {
                ans = min(ans, j - i + 1);
                delBitNum(nums[i], bitAvl);
                i++;
            }
            j++;
        }
        
        return (ans == INT_MAX) ? -1 : ans;
    }
};