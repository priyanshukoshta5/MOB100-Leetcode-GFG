//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int dr[4] = {-1, 0, +1, 0};
    int dc[4] = {0, -1, 0, +1};
    
    bool isValid(int r, int c, int n, int m){
        return r >= 0 && r < n && c >= 0 && c < m ;
    }

    void dfs(int r, int c, vector<vector<char>> &mat, vector<vector<int>> &vis){
        vis[r][c] = 1;
        for(int i = 0; i < 4; i++)
        {
            int newR = r + dr[i];
            int newC = c + dc[i];
            if(isValid(newR, newC, mat.size(), mat[0].size()) && mat[newR][newC] == 'O' && vis[newR][newC] == 0)
                dfs(newR, newC, mat, vis);
        }
    }
    
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        // marking all the componenets which are connected to the boundary of the grid
        for(int i = 0; i < n; i++)
        {
            if(mat[i][0] == 'O' && vis[i][0] == 0)
                dfs(i, 0, mat, vis);
            if(mat[i][m - 1] == 'O' && vis[i][m - 1] == 0)
                dfs(i, m - 1, mat, vis);
        }
        for(int j = 0; j < m; j++)
        {
            if(mat[0][j] == 'O' && vis[0][j] == 0)
                dfs(0, j, mat, vis);
            if(mat[n - 1][j] == 'O' && vis[n - 1][j] == 0)
                dfs(n - 1, j, mat, vis);
        }
        
        vector<vector<char>> ans(n, vector<char> (m, 'X'));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(vis[i][j] == 1)
                    ans[i][j] = 'O';
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends