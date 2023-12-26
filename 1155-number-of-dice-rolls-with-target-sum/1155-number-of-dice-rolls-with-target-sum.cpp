class Solution {
private:
    int MOD = 1e9+7;

public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int> (target + 1, 0));
        // base case
        dp[0][0] = 1;

        long long res;
        for(int ind = 1; ind <= n; ind++)
        {
            for(int tar = 1; tar <= target; tar++)
            {
                res = 0;
                for(int die = 1; die <= k && die <= tar; die++)
                {
                    res += dp[ind - 1][tar - die];
                    res %= MOD;
                }
                dp[ind][tar] = res;
            }
        }

        return dp[n][target];
    }
};