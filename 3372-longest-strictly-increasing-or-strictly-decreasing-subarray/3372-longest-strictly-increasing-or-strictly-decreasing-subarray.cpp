class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        
        int ans = 1;
        for(int i = 0; i < n; i++)
        {
            int temp = 1;
            for(int j = i + 1; j < n; j++)
            {
                if(nums[j - 1] < nums[j])
                    temp++;
                else
                    break;
            }
            ans = max(ans, temp);
        }
        
        for(int i = 0; i < n; i++)
        {
            int temp = 1;
            for(int j = i + 1; j < n; j++)
            {
                if(nums[j - 1] > nums[j])
                    temp++;
                else
                    break;
            }
            ans = max(ans, temp);
        }
        
        return ans;
    }
};