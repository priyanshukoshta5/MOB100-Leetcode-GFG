class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int cur_sum = 0;
        for(int i: nums)
        {
            cur_sum += i;
            ans = max(ans, cur_sum);
            if(cur_sum < 0)
                cur_sum = 0;
        }

        return ans;
    }
};