class Solution {
private:
    int solve(int target, vector<int> &nums, vector<int> &dp){
        if(target == 0)
            return 1;
        if(dp[target] != -1)
            return dp[target];

        int ans = 0;
        for(int num: nums)
        {
            if(num <= target)
                ans += solve(target - num, nums, dp);
        }

        return dp[target] = ans;
    }

public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        return solve(target, nums, dp);
    }
};