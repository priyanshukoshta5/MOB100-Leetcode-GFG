class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        
        vector<bool> dp(n + 1, false);
        
        // base case
        dp[n] = true;
        
        for(int ind = n - 2; ind >= 0; ind--)
        {
            // to store the answer for the array from 'ind' to the end of array
            int ans = false;

            // condition 1: 2 equal elements
            if(nums[ind] == nums[ind + 1])
                ans = ans | dp[ind + 2];

            if((ind + 2) < n)
            {
                // condition 2: 3 equal elements
                if(nums[ind] == nums[ind + 1] && nums[ind + 1] == nums[ind + 2])
                    ans = ans | dp[ind + 3];

                // condition 3: 3 consecutive increasing elements
                if((nums[ind + 1] - nums[ind]) == 1 && (nums[ind + 2] - nums[ind + 1]) == 1)
                    ans = ans | dp[ind + 3];
            }

            dp[ind] = ans;
        }
        
        return dp[0];
    }
};