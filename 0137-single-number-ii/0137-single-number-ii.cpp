class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(32, 0);
        for(int x: nums)
        {
            int val = x;
            for(int i = 31; i >= 0; i--)
            {
                temp[i] += val & 1;
                val = val >> 1;
                if(val == 0)
                    break;
            }
        }

        int ans = 0;
        for(int i = 31; i >= 0; i--)
        {
            if(temp[i] % 3 != 0)
                ans += (1 << (31 - i));
        }

        return ans;
    }
};