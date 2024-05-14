class Solution {
private:
    void getGold(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &vis, int gold, int &maxGold, int m, int n){
        vis[i][j] = 1;

        gold = gold + grid[i][j];
        maxGold = max(maxGold, gold);

        // up
        if((i - 1) >= 0 && vis[i - 1][j] == 0 && grid[i - 1][j] != 0)
            getGold(i - 1, j, grid, vis, gold, maxGold, m, n);

        // right
        if((j + 1) < n && vis[i][j + 1] == 0 && grid[i][j + 1] != 0)
            getGold(i, j + 1, grid, vis, gold, maxGold, m, n);

        // down
        if((i + 1) < m && vis[i + 1][j] == 0 && grid[i + 1][j] != 0)
            getGold(i + 1, j, grid, vis, gold, maxGold, m, n);

        // left
        if((j - 1) >= 0 && vis[i][j - 1] == 0 && grid[i][j - 1] != 0)
            getGold(i, j - 1, grid, vis, gold, maxGold, m, n);

        vis[i][j] = 0;
    }

public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int maxGold = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 0)
                    continue;

                vector<vector<int>> vis(m, vector<int> (n, 0));
                getGold(i, j, grid, vis, 0, maxGold, m, n);
            }
        }

        return maxGold;
    }
};