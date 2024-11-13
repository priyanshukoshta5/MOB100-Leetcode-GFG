// ~Editorial

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long returnVal = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            int targetLowerBoundVal = lower - nums[i];
            int lowerIdx = lower_bound(nums.begin() + i + 1, nums.end(), targetLowerBoundVal) - nums.begin();

            int targetUpperBoundVal = upper - nums[i];
            int upperIdx = upper_bound(nums.begin() + i + 1, nums.end(), targetUpperBoundVal) - nums.begin();
            --upperIdx;
            
            returnVal += upperIdx - lowerIdx + 1;
        }

        return returnVal;
    }
};