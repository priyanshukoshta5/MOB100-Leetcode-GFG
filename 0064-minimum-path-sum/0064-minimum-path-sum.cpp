class Solution {
private: 
    bool isValid(int i, int j){
        return i>=0 && j>=0;
    }
    
    int solve(vector<vector<int>>& grid, int n, int m, vector<vector<int>>& dp){
        if(n == 0 && m == 0)
            return grid[0][0];
        
        if(dp[n][m] != -1)
            return dp[n][m];
        
        int ans = INT_MAX;
        if(isValid(n-1, m))
            ans = solve(grid, n-1, m, dp);
        if(isValid(n, m-1))
            ans = min(ans, solve(grid, n, m-1, dp));
        
        return dp[n][m] = grid[n][m] + ans;
    }
    
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int> (m,-1));
        return solve(grid, n-1, m-1, dp);
    }
};