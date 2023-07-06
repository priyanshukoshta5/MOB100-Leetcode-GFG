class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(nums[0] >= target)
            return 1;
        
        vector<int> prefSum(nums.size());
        prefSum[0] = nums[0];
        for(int i = 1; i < nums.size(); i++)
            prefSum[i] = prefSum[i-1] + nums[i];
        
        int ans = INT_MAX;
        for(int j = 0; j < nums.size(); j++)
        {
            if(prefSum[j] >= target)
            {
                int i = upper_bound(prefSum.begin(), prefSum.begin() + j, prefSum[j] - target) - prefSum.begin();
                ans = min(ans, j-i+1);
            }
        }
        
        return ans == INT_MAX ? 0 : ans;
    }
};