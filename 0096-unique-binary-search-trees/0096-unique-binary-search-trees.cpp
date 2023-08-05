class Solution {
private:
    int solve(int n, vector<int> &dp)
    {
        if(dp[n]!=-1)
            return dp[n];
        
        int cnt = 0;
        for(int i = 1; i <= n; i++)     // choosing the position of the root in the values {1,2,3...}
        {
            int left = solve(i - 1, dp);
            int right = solve(n - i, dp);
            cnt = cnt + left * right;
        }  

        return dp[n] = cnt;
    }
    
public:
    int numTrees(int n) {
        vector<int> dp(n+1, -1);
        dp[0] = 1;
        return solve(n, dp);
    }
};