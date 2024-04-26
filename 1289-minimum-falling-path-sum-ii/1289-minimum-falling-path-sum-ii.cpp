class Solution {
private:
    int solve(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(r == grid.size())
            return 0;
        if(c != -1 && dp[r][c] != -1)
            return dp[r][c];
        
        int res = 1e7;

        for(int i = 0; i < grid.size(); i++)
        {
            if(i == c)
                continue;
            res = min(res, grid[r][i] + solve(r + 1, i, grid, dp));
        }

        if(c != -1)
            return dp[r][c] = res;
        return res;
    }

public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int> (grid.size(), -1));
        return solve(0, -1, grid, dp);
    }
};