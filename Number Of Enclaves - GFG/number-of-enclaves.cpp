//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    int dr[4] = {0, -1, 0, +1};
    int dc[4] = {-1, 0, +1, 0};
  
    bool isValid(int r, int c, int n, int m){
        return r >= 0 && r < n && c >= 0 && c < m ;
    }
  
    void dfs(int r, int c, vector<vector<int>> &grid, vector<vector<bool>> &vis, int n, int m){
        vis[r][c] = true;
        
        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(isValid(nr, nc, n, m) && grid[nr][nc] == 1 && vis[nr][nc] == false)
                dfs(nr, nc, grid, vis, n, m);
        }
    }
    
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Marking all 1's and their neighbors on the 
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        
        // marking first and last col
        for(int r = 0; r < n; r++)
        {
            if(grid[r][0] == 1 && vis[r][0] == false)
                dfs(r, 0, grid, vis, n, m);
                
            if(grid[r][m - 1] == 1 && vis[r][m - 1] == false)
                dfs(r, m - 1, grid, vis, n, m);
        }
        
        // marking first and last row
        for(int c = 0; c < m; c++)
        {
            if(grid[0][c] == 1 && vis[0][c] == false)
                dfs(0, c, grid, vis, n, m);
                
            if(grid[n - 1][c] == 1 && vis[n - 1][c] == false)
                dfs(n - 1, c, grid, vis, n, m);
        }
        
        // counting all the 1's which are not the part of any segment leading to boundary
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1 && vis[i][j] == false)
                {
                    cnt++;
                    // cout<<i<<" "<<j<<endl;
                }
            }
        }
        
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends