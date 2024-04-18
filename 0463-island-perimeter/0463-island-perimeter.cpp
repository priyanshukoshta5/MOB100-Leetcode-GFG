class Solution {
bool isBoundary(int r, int c, int n, int m, vector<vector<int>> &grid){
    return r < 0 || r == n || c < 0 || c == m || grid[r][c] == 0; 
}

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 0)
                    continue;
                ans = ans + 
                      isBoundary(i + 1, j, n, m, grid) + 
                      isBoundary(i - 1, j, n, m, grid) + 
                      isBoundary(i, j + 1, n, m, grid) +
                      isBoundary(i, j - 1, n, m, grid);
            }
        }
        return ans;
    }
};