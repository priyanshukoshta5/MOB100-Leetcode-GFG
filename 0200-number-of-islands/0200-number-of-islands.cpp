class Solution {
private:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    
    bool isSafe(int r, int c, int n, int m){
        return r >= 0 && r < n && c >= 0 && c < m ;
    }
    
    void dfs(int r, int c, int n, int m, vector<vector<char>>& grid, vector<vector<int>>& vis){
        vis[r][c] = 1;
        for(int i = 0; i < 4; i++)
        {
            int newR = r + dr[i];
            int newC = c + dc[i];
            if(isSafe(newR, newC, n, m) == true && grid[newR][newC] == '1' && vis[newR][newC] == 0)
                dfs(newR, newC, n, m, grid, vis);
        }
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        int islands = 0;
        for(int r = 0; r < n; r++)
        {
            for(int c = 0; c < m; c++)
            {
                if(vis[r][c] == 0 && grid[r][c] == '1')
                {
                    islands++;
                    dfs(r, c, n, m, grid, vis);
                }
            }
        }
        
        return islands;
    }
};