class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int> (1200, 1));

        int ans = 0;
        for(int prev = 0; prev < n; prev++)
        {
            for(int cur = prev+1; cur < n; cur++)
            {
                int diff = nums[cur] - nums[prev] + 510;
                dp[cur][diff] = 1 + dp[prev][diff];
                ans = max(ans, dp[cur][diff]);
            }
        }

        return ans;
    }
};