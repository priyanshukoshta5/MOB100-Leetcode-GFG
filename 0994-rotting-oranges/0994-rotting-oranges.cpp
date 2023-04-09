class Solution {
public:
    // ~ Striver
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size(), days = 0, tot = 0, cnt = 0;
        queue<pair<int, int>> rotten;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] != 0) tot++;
                if(grid[i][j] == 2) rotten.push({i, j});
            }
        }
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        while(!rotten.empty()){
            int k = rotten.size();
            cnt += k; 
            while(k--){
                int x = rotten.front().first, y = rotten.front().second;
                rotten.pop();
                for(int i = 0; i < 4; ++i){
                    int nx = x + dx[i], ny = y + dy[i];
                    if(nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1) continue;
                    grid[nx][ny] = 2;
                    rotten.push({nx, ny});
                }
            }
            if(!rotten.empty()) days++;
        }
        
        return tot == cnt ? days : -1;
    }
    
    /*
    My Solution
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q; // {{i,j}}
        vector<vector<int>> vis(n, vector<int> (m,0));
        int freshOranges = 0;
        int days = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 1)
                {
                    freshOranges++;
                }
                if(grid[i][j] == 2)
                {
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }
        if(freshOranges == 0)
            return 0;

        int dr[] = {0,+1,0,-1};
        int dc[] = {-1,0,+1,0};
        while(!q.empty())
        {
            int cnt = q.size();
            while(cnt--)
            {
                auto it = q.front();
                q.pop();
                int r = it.first;
                int c = it.second;
                for(int i=0; i<4; i++)
                {
                    int newR = r + dr[i];
                    int newC = c + dc[i]; 
                    if(isValid(newR, newC, n, m) && grid[newR][newC]==1 && vis[newR][newC]==0)
                    {
                        vis[newR][newC] = 1;
                        q.push({newR, newC});
                        freshOranges--;
                        if(freshOranges == 0)
                            return days+1;
                    }
                }
            }
            if(!q.empty())
                days++;
        }
        return -1;
    }
    */
};