class Solution {
private:
    int solve(vector<int>& coins, int amount, vector<int> &dp){
        if(amount == 0) return 0;
        if(amount < 0) return INT_MAX;

        if(dp[amount] != -1)
            return dp[amount];

        long long ans = INT_MAX;
        for(int i: coins)
            ans = min(ans, 1LL + solve(coins, amount - i, dp));

        return dp[amount] = ans;
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)
            return 0;

        vector<int> dp(amount+1, -1);
        int ans = solve(coins, amount, dp);
        return ans == INT_MAX ? -1 : ans;
    }
};