class Solution {
private:
    vector<int> dr = {0,-1,0,+1};
    vector<int> dc = {-1,0,+1,0};

    int isSafe(int r, int c, int n, int m){
        return r>=0 && r<n && c>=0 && c<m;
    }

    void dfs(vector<vector<int>>& grid, int n, int m, int r, int c, vector<vector<int>>& vis, int& cnt){
        vis[r][c] = 1;
        cnt++;
        for(int i=0; i<4; i++)
        {
            int R = r+dr[i];
            int C = c+dc[i];
            if(isSafe(R,C,n,m) && grid[R][C]==1 && vis[R][C]==0)
                dfs(grid, n, m, R, C, vis, cnt);
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m,0));
        int cnt = 0;

        // Marking boundaries
        for(int i=0; i<n; i++)
        {
            if(!vis[i][0] && grid[i][0]==1) dfs(grid, n, m, i, 0, vis, cnt);
            if(!vis[i][m-1] && grid[i][m-1]==1) dfs(grid, n, m, i, m-1, vis, cnt);
        }
        for(int j=0; j<m; j++)
        {
            if(!vis[0][j] && grid[0][j]==1) dfs(grid, n, m, 0, j, vis, cnt);
            if(!vis[n-1][j] && grid[n-1][j]==1) dfs(grid, n, m, n-1, j, vis, cnt);
        }

        // Searching for the inner 1's        
        cnt = 0;
        for(int i=1; i<n-1; i++)
            for(int j=1; j<m-1; j++)
                if(grid[i][j]==1 && !vis[i][j])
                    dfs(grid, n, m, i, j, vis, cnt);
        
        return cnt;
    }   
};