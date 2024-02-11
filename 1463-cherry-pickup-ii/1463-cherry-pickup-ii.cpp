class Solution {
private:
    int dp[70][70][70];

    int isValid(int r, int c, int n, int m){
        return r >= 0 && r < n && c >= 0 && c < m;
    }

    int maxCherry(vector<vector<int>> &grid, int i, int r1y, int r2y, int rows, int cols){
        if(dp[i][r1y][r2y] != -1)
            return dp[i][r1y][r2y];

        int c1 = grid[i][r1y];
        grid[i][r1y] = 0;

        int c2 = grid[i][r2y];
        grid[i][r2y] = 0;

        int res = 0;
        for(int j1 = -1; j1 <= 1; j1++)
        {
            if(!isValid(i + 1, r1y + j1, rows, cols))
                continue;

            for(int j2 = -1; j2 <= 1; j2++)
            {
                if(!isValid(i + 1, r2y + j2, rows, cols))
                    continue;

                res = max(res, maxCherry(grid, i + 1, r1y + j1, r2y + j2, rows, cols));
            }
        }

        grid[i][r2y] = c2;
        grid[i][r1y] = c1;

        return dp[i][r1y][r2y] = (res + c1 + c2);
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return maxCherry(grid, 0, 0, cols - 1, rows, cols);
    }
};