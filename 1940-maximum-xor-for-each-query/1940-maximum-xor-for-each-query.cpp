class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();

        vector<int> ans(n);
        int XOR = 0;
        for(int i = 0; i < n; i++)
        {
            XOR = XOR ^ nums[i];
            int k = 0;
            for(int b = 0; b < maximumBit; b++)
            {
                if(((XOR >> b) & 1) == 0)
                    k = k | (1 << b);
            }
            // cout<<XOR<<" "<<k<<endl;
            ans[n - i - 1] = k;
        }

        return ans;
    }
};