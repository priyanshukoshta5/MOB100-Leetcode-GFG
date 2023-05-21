class Solution {
private:
    bool isValid(int n, int i, int j){
        return i>=0 && i<n && j>=0 && j<n;
    }

    void dfs(vector<vector<int>>& grid, int i, int j, vector<pair<int,int>>& island, vector<vector<int>>& visited){
        visited[i][j] = 1;
        island.push_back({i,j});

        int dr[] = {-1, 0, +1, 0};
        int dc[] = {0, +1, 0, -1};

        for(int k=0; k<4; k++)
        {
            int r = i + dr[k];
            int c = j + dc[k];
            if(isValid(grid.size(), r, c) && grid[r][c] == 1 && visited[r][c] == 0)
                dfs(grid, r, c, island, visited);
        }
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int,int>> island_1, island_2;
        vector<vector<int>> visited(n, vector<int> (n,0));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1 && visited[i][j] == 0)
                {
                    if(island_1.size() == 0)
                        dfs(grid, i, j, island_1, visited);
                    else
                        dfs(grid, i, j, island_2, visited);
                }
            }
        }

        // for(auto x: island_1)
        //     cout<<x.first<<" "<<x.second<<endl;
        // cout<<endl;
        // for(auto x: island_2)
        //     cout<<x.first<<" "<<x.second<<endl;

        int shorted_bridge = INT_MAX;
        for(auto x: island_1)
        {
            for(auto y: island_2)
            {
                int dist = abs(x.first - y.first) + abs(x.second - y.second) - 1;
                shorted_bridge = min(shorted_bridge, dist);
            }
        }

        return shorted_bridge;
    }
};