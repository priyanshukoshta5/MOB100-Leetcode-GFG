class Solution {
private:
    int runMyFunctionRun(int ind, vector<int> &nums, int curVal, int maxOR){
        if(ind == nums.size())
            return curVal == maxOR;

        int take = runMyFunctionRun(ind + 1, nums, curVal | nums[ind], maxOR);
        int notTake = runMyFunctionRun(ind + 1, nums, curVal, maxOR);

        return take + notTake;
    }

public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR = 0;
        for(int i: nums)
            maxOR = maxOR | i;

        return runMyFunctionRun(0, nums, 0, maxOR);
    }
};