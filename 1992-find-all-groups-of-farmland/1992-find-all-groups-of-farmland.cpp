class Solution {
private:
    void dfs(int i, int j, vector<vector<int>> &land, vector<vector<bool>> &vis, vector<vector<int>> &ans, int n, int m){
        ans.back()[2] = max(ans.back()[2], i);
        ans.back()[3] = max(ans.back()[3], j);
        
        vis[i][j] = true;

        if((i + 1) < n && vis[i + 1][j] == false && land[i + 1][j] == 1)
            dfs(i + 1, j, land, vis, ans, n, m);

        if((j + 1) < m && vis[i][j + 1] == false && land[i][j + 1] == 1)
            dfs(i, j + 1, land, vis, ans, n, m);
    }

public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();

        vector<vector<int>> ans;
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!vis[i][j] && land[i][j] == 1)
                {
                    ans.push_back({i, j, i, j});
                    dfs(i, j, land, vis, ans, n, m);
                }
            }
        }

        return ans;
    }
};