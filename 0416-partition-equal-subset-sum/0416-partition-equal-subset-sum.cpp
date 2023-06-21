class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i: nums)
            sum += i;
        
        if(sum % 2 == 1)
            return false;
        
        int n = nums.size();
        int target = sum / 2;
        vector<int> prev(target+1, false), cur(target+1, false);

        for(int i = n-1; i >= 1; i--)
        {
            // Base Case
            prev[0] = true;
            
            for(int t = 1; t <= target; t++)
            {
                bool ans;
                if(nums[i] <= t)
                    ans = prev[t] || prev[t-nums[i]];
                else
                    ans = prev[t];
                cur[t] = ans;
            }
            prev = cur;
        }

        return prev[target];
        
        // Time - O(n * target)
        // Space - O(2 * target)
    }
};