class Solution {
private:
    int dr[4] = {0, +1, 0, -1};
    int dc[4] = {+1, 0, -1, 0};
    
    bool isValid(int r, int c, int n, int m){
        return r >= 0 && r < n && c >= 0 && c < m;
    }

public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();

        queue<pair<int, int>> q;        
        vector<vector<int>> ans(n, vector<int> (m, -1));
        // marking water and its adjacents 
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(isWater[i][j] == 1)
                {
                    ans[i][j] = 0;
                    for(int x = 0; x < 4; x++)
                    {
                        int r = i + dr[x];
                        int c = j + dc[x];
                        if(isValid(r, c, n, m) && isWater[r][c] != 1 && ans[r][c] == -1) 
                        {
                            ans[r][c] = 1;
                            q.push({r, c});
                        }
                    }
                }
            }
        }

        // using BFS to fill remaining cells
        int maxHeight = 0;
        while(!q.empty())
        {
            auto it = q.front(); q.pop();
            int r = it.first;
            int c = it.second;
            for(int x = 0; x < 4; x++)
            {
                int nR = r + dr[x];
                int nC = c + dc[x];
                if(isValid(nR, nC, n, m) && ans[nR][nC] == -1)
                {
                    ans[nR][nC] = ans[r][c] + 1;
                    q.push({nR, nC});
                }
            }
        }

        return ans;
    }
};