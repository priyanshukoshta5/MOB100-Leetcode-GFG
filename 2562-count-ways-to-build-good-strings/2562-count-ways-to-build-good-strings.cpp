class Solution {
private:
    int MOD = 1e9+7;
    
    int solve(int low, int high, int zero, int one, int len, vector<int>& dp){
        if(len > high)
            return 0;
        
        if(dp[len] != -1)
            return dp[len];
        
        long long int ans = 0;
        if(len >= low && len <= high)
            ans++;
        
        ans += solve(low, high, zero, one, len + zero, dp);
        ans += solve(low, high, zero, one, len + one, dp);
        
        return dp[len] = ans % MOD;
    }
        
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1, -1);
        return solve(low, high, zero, one, 0, dp);
    }
};