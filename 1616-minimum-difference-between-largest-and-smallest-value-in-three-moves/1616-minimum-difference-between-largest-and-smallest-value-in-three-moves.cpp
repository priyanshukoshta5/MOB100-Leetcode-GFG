class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n <= 4)
            return 0;
        
        sort(nums.begin(), nums.end());

        int ans = INT_MAX;
        
        ans = min(ans, nums[n - 1] - nums[3]);    // removed 3 left, 0 right
        ans = min(ans, nums[n - 2] - nums[2]);    // removed 2 left, 1 right
        ans = min(ans, nums[n - 3] - nums[1]);    // removed 1 left, 2 right
        ans = min(ans, nums[n - 4] - nums[0]);    // removed 0 left, 3 right

        return ans;
    }
};