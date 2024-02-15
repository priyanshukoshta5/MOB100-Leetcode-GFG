class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        long long sum = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            if(i > 1 && sum > nums[i])
                ans = max(ans, sum + nums[i]);
            sum += nums[i];
        }
        if(ans == 0)
            return -1;
        return ans;
    }
};