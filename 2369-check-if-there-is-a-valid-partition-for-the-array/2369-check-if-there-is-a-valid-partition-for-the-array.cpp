class Solution {
private:
    bool solve(int ind, vector<int>& nums, vector<int> &dp){
        // reached the end of the array
        if(ind == nums.size())  
            return true;

        // only 1 element left    
        if(ind == nums.size() - 1)  
            return false;

        // if already calculated
        if(dp[ind] != -1)
            return dp[ind];

        // to store the answer for the array from 'ind' to the end of array
        int ans = false;

        // condition 1: 2 equal elements
        if(nums[ind] == nums[ind + 1])
            ans = ans | solve(ind + 2, nums, dp);

        if((ind + 2) < nums.size())
        {
            // condition 2: 3 equal elements
            if(nums[ind] == nums[ind + 1] && nums[ind + 1] == nums[ind + 2])
                ans = ans | solve(ind + 3, nums, dp);

            // condition 3: 3 consecutive increasing elements
            if((nums[ind + 1] - nums[ind]) == 1 && (nums[ind + 2] - nums[ind + 1]) == 1)
                ans = ans | solve(ind + 3, nums, dp);
        }

        return dp[ind] = ans;
    }

public:
    bool validPartition(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(0, nums, dp);
    }
};