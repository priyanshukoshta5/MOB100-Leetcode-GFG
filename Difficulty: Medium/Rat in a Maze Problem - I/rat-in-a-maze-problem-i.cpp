//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  private:
        //   { right, down, left, up }
        int dr[4] = {0, +1, 0, -1};
        int dc[4] = {+1, 0, -1, 0};
        char dir[4] = {'R', 'D', 'L', 'U'};
    
    bool isValid(int r, int c, int n){
        return r>=0 && r<n && c>=0 && c<n;
    }
    
    void solve(int n, vector<vector<int>>& mat, int r, int c, string& dirs, vector<vector<int>>& vis, vector<string>& ans){
        if(r == n-1 && c == n-1)
        {
            ans.push_back(dirs);
            return;
        }
        
        for(int i=0; i<4; i++)
        {
            int newr = r+dr[i];
            int newc = c+dc[i];
            if(isValid(newr, newc, n) == true && mat[newr][newc] == 1 && vis[newr][newc] == 0)
            {
                vis[newr][newc] = 1;
                dirs.push_back(dir[i]);
                solve(n, mat, newr, newc, dirs, vis, ans);
                dirs.pop_back();
                vis[newr][newc] = 0;
            }
        }
    }
  
  
  public:
    vector<string> findPath(vector<vector<int>> &m) {
        int n = m.size();
        if(m[0][0] == 0 || m[n-1][n-1] == 0)
            return {};
            
        vector<string> ans;
        string dirs;
        vector<vector<int>> vis(n, vector<int> (n,0));
        vis[0][0] = 1;
        solve(n, m, 0, 0, dirs, vis, ans);
        
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends