class Solution {
private:
    bool isValid(int r, int c, int n, int m){
        return r >= 0 && r < n && c >= 0 && c < m;
    }

    int solve(int r, int c, vector<vector<int>>& grid, vector<vector<int>> &dp){
        if(dp[r][c] != -1)
            return dp[r][c];
        
        int res = 0;
        for(int i = -1; i <= 1; i++)
        {
            int nR = r + i;
            int nC = c + 1;
            if(isValid(nR, nC, grid.size(), grid[0].size()) && grid[nR][nC] > grid[r][c])
                res = max(res, 1 + solve(nR, nC, grid, dp));
        }

        return dp[r][c] = res;
    }

public:
    int maxMoves(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int> (grid[0].size(), -1));
        int ans = 0;
        for(int r = 0; r < grid.size(); r++)
            ans = max(ans, solve(r, 0, grid, dp));
        return ans;
    }
};