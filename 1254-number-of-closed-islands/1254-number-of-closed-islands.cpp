class Solution {
private:
    bool isSafe(int i, int j, int n, int m){
        return i>=0 && i<n && j>=0 && j<m;
    }

    void bfs(vector<vector<int>>& grid, int n, int m, vector<vector<int>>& vis, int r, int c){
        int dr[] = {-1,0,+1,0};
        int dc[] = {0,+1,0,-1};

        queue<pair<int,int>> q; // {row,col}
        q.push({r,c});

        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0; i<4; i++)
            {
                int newR = row + dr[i];
                int newC = col + dc[i];
                if(isSafe(newR, newC, n, m) && vis[newR][newC]==0 && grid[newR][newC] == 0)
                {
                    vis[newR][newC] = 1;
                    q.push({newR, newC});
                }
            } 
        }
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;
        vector<vector<int>> vis(n, vector<int> (m,0));
        // Marking the boundary islands, as we dont need them
        for(int i=0; i<n; i++)
        {
            if(grid[i][0] == 0 && vis[i][0] == 0)
            {
                vis[i][0] = 1;
                bfs(grid, n, m, vis, i, 0);
            }
            if(grid[i][m-1] == 0 && vis[i][m-1] == 0)
            {
                vis[i][m-1] = 1;
                bfs(grid, n, m, vis, i, m-1);
            }
        }
        for(int j=0; j<m; j++)
        {
            if(grid[0][j] == 0 && vis[0][j] == 0)
            {
                vis[0][j] = 1;
                bfs(grid, n, m, vis, 0, j);
            }
            if(grid[n-1][j] == 0 && vis[n-1][j] == 0)
            {
                vis[n-1][j] = 1;
                bfs(grid, n, m, vis, n-1, j);
            }
        }


        for(int i=1; i<n-1; i++)
        {
            for(int j=1; j<m-1; j++)
            {
                if(grid[i][j] == 0 && vis[i][j] == 0)
                {
                    cnt++;
                    vis[i][j] = 1;
                    bfs(grid, n, m, vis, i, j);
                }
            }
        }

        return cnt;
    }
};