class Solution {
private:
    int dr[4] = {-1, 0, +1, 0};
    int dc[4] = {0, -1, 0, +1};

    bool isValid(int r, int c, int n, int m){
        return r >= 0 && r < n && c >= 0 && c < m;
    }

    bool traverse(int r, int c, int n, int m, vector<vector<int>> &grid1, vector<vector<int>> &grid2, vector<vector<int>> &vis){
        vis[r][c] = 1;
        bool flag = true;
        if(grid1[r][c] == 0)
            flag = false;
        for(int i = 0; i < 4; i++)
        {
            int nR = r + dr[i];
            int nC = c + dc[i];
            if(isValid(nR, nC, n, m) && vis[nR][nC] == 0 && grid2[nR][nC] == 1)
                flag = flag & traverse(nR, nC, n, m, grid1, grid2, vis);
        }
        return flag;
    }

public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        int cnt = 0;
        vector<vector<int>> vis(n, vector<int> (m, 0));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(vis[i][j] == 0 && grid2[i][j] == 1)
                {
                    bool res = traverse(i, j, n, m, grid1, grid2, vis);
                    if(res == true)
                    {
                        cnt++;
                        // cout<<i<<" "<<j<<endl;
                    }
                }
            }
        }
        return cnt;
    }
};