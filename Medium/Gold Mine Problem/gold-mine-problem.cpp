//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int solve(int r, int c, vector<vector<int>> &mat, int n, int m, vector<vector<int>> &dp){
        if(dp[r][c] != -1)
            return dp[r][c];
        
        int res = 0;

        // upper diagonal
        if((r - 1) >= 0 && (c + 1) < m)
            res = max(res, solve(r - 1, c + 1, mat, n, m, dp));
        
        // right
        if((c + 1) < m)
            res = max(res, solve(r, c + 1, mat, n, m, dp));
        
        // lower diagonal
        if((r + 1) < n && (c + 1) < m)
            res = max(res, solve(r + 1, c + 1, mat, n, m, dp));
        
        return dp[r][c] = mat[r][c] + res;
    }
    
public:
    int maxGold(int n, int m, vector<vector<int>> &M)
    {
        vector<vector<int>> dp(n, vector<int> (m, -1));
        int ans = 0;
        for(int r = 0; r < n; r++)
            ans = max(ans, solve(r, 0, M, n, m, dp));
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
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends