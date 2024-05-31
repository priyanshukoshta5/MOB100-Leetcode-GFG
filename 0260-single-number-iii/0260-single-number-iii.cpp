class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int XOR = 0;
        for(auto i: nums)
            XOR = XOR ^ i;

        unsigned int lowestBit = XOR & -(unsigned int)XOR;

        vector<int> ans(2, 0);
        for (int i: nums) 
        {
            if ((lowestBit & i) == 0) 
                ans[0] ^= i;
            else
                ans[1] ^= i;
        }

        return ans;
    }
};