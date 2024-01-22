class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mis, rep;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i > 0 && nums[i - 1] == nums[i])
                rep = nums[i];
            sum = sum + (i + 1) - nums[i];
        }
        return {rep, abs(sum + rep)};
    }
};