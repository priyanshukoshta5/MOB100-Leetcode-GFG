class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<int> freq32(32, 0);
        for(int i: nums)
        {
            int j = 0;
            int val = i;
            while(j < 32)
            {
                freq32[j] += val % 2;
                val = val / 2;
                j++;
            }
        }
        
        int ops = 0;
        int i = 0;
        while(i < 32)
        {
            if((k % 2) == 0 && (freq32[i] % 2) == 1)
                ops++;
            if((k % 2) == 1 && (freq32[i] % 2) == 0)
                ops++;
            i++;
            k = k / 2;
        }
            
        return ops;
    }
};