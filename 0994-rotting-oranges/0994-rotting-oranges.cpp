class Solution {
private:
    bool isValid(int r, int c, int n, int m){
        return r>=0 && r<n && c>=0 && c<m;
    }

public:
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
};