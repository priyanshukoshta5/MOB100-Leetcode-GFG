class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        // vector<int> dp(n + 1, 0);
        int i2 = 0;             // dp[n] = 0;
        int i1 = nums[n - 1];    // dp[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--)
        {
            int cur = 0;

            // skip ith house
            cur = max(cur, i1);  //dp[i] = max(dp[i], dp[i + 1]);

            // rob ith house
            cur = max(cur, nums[i] + i2);  //dp[i] = max(dp[i], nums[i] + dp[i + 2]);

            i2 = i1; 
            i1 = cur;
        }

        return i1;
    }
};