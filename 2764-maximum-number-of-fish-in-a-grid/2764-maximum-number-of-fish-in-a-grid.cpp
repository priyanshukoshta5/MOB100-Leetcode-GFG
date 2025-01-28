// class Solution {
// private:
//     int dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &vis){
//         vis[i][j] = true;
//         int res = vis[i][j];

//         // right
//         if((j + 1) < grid[0].size() && vis[i][j + 1] == false && grid[i][j + 1] > 0)
//             res += dfs(i, j + 1, grid, vis);

//         // down
//         if((i + 1) < grid.size() && vis[i + 1][j] == false && grid[i + 1][j] > 0)
//             res += dfs(i + 1, j, grid, vis);

//         // left
//         if((j - 1) >= 0 && vis[i][j - 1] == false && grid[i][j - 1] > 0)
//             res += dfs(i, j - 1, grid, vis);

//         // up
//         if((i - 1) >= 0 && vis[i - 1][j] == false && grid[i - 1][j] > 0)
//             res += dfs(i - 1, j, grid, vis);

//         // cout<<i<<" "<<j<<" "<<res<<endl;

//         return res;
//     }

// public:
//     int findMaxFish(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();

//         int ans = 0;
//         vector<vector<bool>> vis(n, vector<bool> (m, 0));
//         for(int i = 0; i < n; i++)
//         {
//             for(int j = 0; j < m; j++)
//             {
//                 if(vis[i][j] == false && grid[i][j] > 0)
//                 {
//                     ans = max(ans, dfs(i, j, grid, vis));
//                     cout<<i<<" "<<j<<" "<<ans<<endl;
//                 }
//             }
//         }

//         return ans;
//     }
// };

class Solution {
private:
    // Helper function to count the number of fishes in a connected component
    int calculateFishes(vector<vector<int>>& grid,
                        vector<vector<bool>>& visited, int row, int col) {
        // Check boundary conditions, water cells, or already visited cells
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() ||
            grid[row][col] == 0 || visited[row][col]) {
            return 0;
        }

        // Mark the current cell as visited
        visited[row][col] = true;

        // Accumulate the fish count from the current cell and its neighbors
        return grid[row][col] + calculateFishes(grid, visited, row, col + 1) +
               calculateFishes(grid, visited, row, col - 1) +
               calculateFishes(grid, visited, row + 1, col) +
               calculateFishes(grid, visited, row - 1, col);
    }

public:
    int findMaxFish(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int maxFishCount = 0;

        // A 2D vector to track visited cells
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        // Iterate through all cells in the grid
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                // Start a DFS for unvisited land cells (fish available)
                if (grid[row][col] > 0 && !visited[row][col]) {
                    maxFishCount = max(
                        maxFishCount, calculateFishes(grid, visited, row, col));
                }
            }
        }

        // Return the maximum fish count found
        return maxFishCount;
    }
};