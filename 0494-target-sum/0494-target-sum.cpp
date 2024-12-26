class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target, int ind = 0) {
        if(ind == nums.size())
        {
            if(target == 0)
                return 1;
            return 0;
        }

        // adding + sign
        int plus = findTargetSumWays(nums, target - nums[ind], ind + 1);

        // adding - sign
        int minus = findTargetSumWays(nums, target + nums[ind], ind + 1);

        return plus + minus;
    }
};