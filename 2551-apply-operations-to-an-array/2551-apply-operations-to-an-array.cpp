class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int i, j, k, n=nums.size();
        i = 0;
        while(i<n-1)
        {
            if(nums[i]==nums[i+1])
            {
                nums[i] *= 2;
                nums[i+1] = 0;
            }
            i++;
        }
        vector<int> ans(n);
        i = 0;
        k = 0;
        j = n-1;
        while(k<n)
        {
            if(nums[k]==0)
            {
                ans[j] = 0;
                j--;
            }
            else
            {
                ans[i] = nums[k];
                i++;
            }
            k++;
        }
        return ans;
    }
};