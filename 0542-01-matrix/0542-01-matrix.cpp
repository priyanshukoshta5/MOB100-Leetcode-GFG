class Solution {
private:
    int dr[4] = {-1, 0, +1, 0};
    int dc[4] = {0, +1, 0, -1};

    int isValid(int r, int c, int n, int m){
        return r >= 0 && r < n && c >= 0 && c < m ;
    }

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int oneCount = 0;
        queue<pair<int, pair<int,int>>> q;      // {dist, {r,c}}
        vector<vector<int>> ans(n, vector<int> (m, -1));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({0, {i,j}});
                    ans[i][j] = 0;
                }
                else
                    oneCount++;
            }
        }

        // BFS
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int dist = it.first;
            int r = it.second.first;
            int c = it.second.second;
            for(int i = 0; i < 4; i++)
            {
                int newR = r + dr[i];
                int newC = c + dc[i];
                if(isValid(newR, newC, n, m) && ans[newR][newC] == -1)  // valid + not visited
                {
                    ans[newR][newC] = dist + 1;
                    q.push({dist + 1, {newR, newC}});
                }
            }
        }

        return ans;
    }
};