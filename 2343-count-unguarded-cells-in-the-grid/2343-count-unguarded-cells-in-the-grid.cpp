class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // 0 for free, 1 for wall, 2 for guards, 3 for guards view, 
        vector<vector<int>> grid(m, vector<int> (n, 0));
        int r, c;

        // marking walls
        for(auto w: walls)
            grid[w[0]][w[1]] = 1;

        // marking guards
        for(auto g: guards)
            grid[g[0]][g[1]] = 2;

        // marking guard views
        for(auto g: guards)
        {
            r = g[0], c = g[1] + 1;
            while(c < n && grid[r][c] != 1 && grid[r][c] != 2)
            {
                grid[r][c] = 3;
                c++;
            }

            r = g[0], c = g[1] - 1;
            while(c >= 0 && grid[r][c] != 1 && grid[r][c] != 2)
            {
                grid[r][c] = 3;
                c--;
            }

            r = g[0] - 1, c = g[1];
            while(r >= 0 && grid[r][c] != 1 && grid[r][c] != 2)
            {
                grid[r][c] = 3;
                r--;
            }

            r = g[0] + 1, c = g[1];
            while(r < m && grid[r][c] != 1 && grid[r][c] != 2)
            {
                grid[r][c] = 3;
                r++;
            }
        }

        int ans = 0;
        for(auto row: grid)
        {
            for(int cell: row)
            {
                ans = ans + (cell == 0);
                // cout<<cell<<" ";
            }
            // cout<<endl;
        }

        return ans;
    }
};