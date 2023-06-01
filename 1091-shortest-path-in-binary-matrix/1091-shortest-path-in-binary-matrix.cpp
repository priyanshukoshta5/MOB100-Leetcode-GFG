class Solution {
public:
    int isSafe(int r, int c, int n){
        return r >= 0 && r < n && c >= 0 && c < n ;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1)
            return -1;
        
        int n = grid.size();
        
        if(n == 1)
            return grid[0][0] == 0 ? 1 : -1 ;
        
        vector<vector<int>> visited(n, vector<int> (n,0));
        
        queue<pair<int, pair<int, int>>> q;  // {dist, {r, c}}
        q.push({1, {0, 0}});
        visited[0][0] = 1;
        
        int minPath = -1;
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int dist = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            if(r == n-1 && c == n-1)
            {
                minPath = dist;
                break;
            }
            
            for(int i = -1; i <= 1; i++)
            {
                for(int j = -1; j <= 1; j++)
                {
                    int newR = r + i;
                    int newC = c + j;
                    if(isSafe(newR, newC, n) == true && grid[newR][newC] == 0 && visited[newR][newC] == 0)
                    {
                        visited[newR][newC] = 1;
                        q.push({dist + 1, {newR, newC}});
                    }
                }
            }
        }
        
        return minPath;
    }
};