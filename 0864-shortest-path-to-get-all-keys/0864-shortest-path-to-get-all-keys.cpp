// ~ references : rx3360441619

class Solution {
private:
    bool isValid(int r, int c, int n, int m){
        return r >= 0 && r < n && c >=0 && c < m ;
    }

    bool isKey(char ch){
        return ch >= 'a' && ch <= 'z';
    }

    bool isLock(char ch){
        return ch >= 'A' && ch <= 'Z';
    }

public:
    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(n == 0 || m == 0)
            return 0;
        
        queue<pair<int, pair<int,int>>> q;
        vector<vector<vector<int>>> vis(n, vector<vector<int>> (m, vector<int> (64, 0)));
        int nKeys = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == '@')
                {
                    q.push({0, {i,j}});
                    vis[i][j][0] = 1;
                }
                else if(isKey(grid[i][j]))
                    nKeys++;
            }
        }

        if(nKeys == 0)
            return 0;

        int dr[4] = {0, -1, 0, +1};
        int dc[4] = {-1, 0, +1, 0};

        int steps = 0;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                auto it = q.front(); 
                q.pop();
                int k = it.first;
                int i = it.second.first;
                int j = it.second.second;
                if(k == ((1 << nKeys) - 1))
                    return steps;
                for(int z = 0; z < 4; z++)
                {
                    int ni = i + dr[z];
                    int nj = j + dc[z];
                    int curKeys = k;
                    if(isValid(ni, nj, n, m))
                    {
                        char ch = grid[ni][nj];

                        if(ch == '#') 
                            continue;
                        
                        if(isKey(ch))
                            curKeys = k | (1 << (ch-'a'));  // adding the new key
                        else if(isLock(ch))
                            if(!(curKeys & (1 << (ch-'A'))))  // it dont have the required key
                                continue;

                        if(vis[ni][nj][curKeys] == 0)
                        {
                            q.push({curKeys, {ni,nj}});
                            vis[ni][nj][curKeys] = 1;
                        }
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};