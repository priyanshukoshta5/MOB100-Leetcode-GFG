//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  private:
    int solve(int i, int j, string& A, vector<vector<int>> &dp){
        if(i > j)
            return 0;
        if(i == j)
            return 1;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        // If characters matched
        if(A[i] == A[j])
            return dp[i][j] = 2 + solve(i+1, j-1, A, dp);
            
        // else
        return dp[i][j] = max(solve(i+1, j, A, dp), solve(i, j-1, A, dp));
    }
    
  public:
    int longestPalinSubseq(string &A) {
        // code here
        int n = A.length();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solve(0, n-1, A, dp);
    }
};


//{ Driver Code Starts.

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends