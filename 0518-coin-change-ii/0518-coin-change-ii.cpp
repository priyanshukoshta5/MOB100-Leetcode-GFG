class Solution {
private:
    int coinChange(vector<int>& coins, int ind, int T, vector<vector<int>>& dp){
        if(ind == 0)
            return (T % coins[0] == 0);
        
        if(dp[ind][T] != -1)
            return dp[ind][T];
            
        int notTaken = coinChange(coins, ind - 1, T, dp);
        
        int taken = 0;
        if(coins[ind] <= T)
            taken = coinChange(coins, ind, T - coins[ind], dp);
            
        return dp[ind][T] = notTaken + taken;
    }

public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return coinChange(coins, n - 1, amount, dp);
    }
};