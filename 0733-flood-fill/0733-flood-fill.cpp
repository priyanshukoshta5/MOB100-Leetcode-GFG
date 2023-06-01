class Solution {
public:
    bool isSafe(int r, int c, int n, int m){
        return r >= 0 && r < n && c >= 0 && c < m ;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<int>> visited(n, vector<int> (m, 0));
        vector<vector<int>> grid = image;

        int dr[] = {0,+1,0,-1};
        int dc[] = {-1,0,+1,0};

        queue<pair<int,int>> q;
        q.push({sr, sc});
        visited[sr][sc] = 1;
        int orgCol = grid[sr][sc];
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            grid[r][c] = color;
            q.pop();

            for(int i=0; i<4; i++)
            {
                int newR = r + dr[i];
                int newC = c + dc[i];
                if( isSafe(newR, newC, n, m) == true 
                    && visited[newR][newC] == 0 
                    && grid[newR][newC] == orgCol)
                {
                    q.push({newR, newC});
                    visited[newR][newC] = 1;
                }
            }
        }

        return grid;
    }
};