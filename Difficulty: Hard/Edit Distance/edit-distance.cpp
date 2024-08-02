//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        // cout<<i<<" "<<j<<endl;
        if(i == -1 && j == -1)
            return 0;
        if(i == -1 || j == -1)
            return max(i + 1, j + 1);
        if(dp[i][j] != -1)
            return dp[i][j];
            
        if(s1[i] == s2[j])
            return dp[i][j] = solve(i - 1, j - 1, s1, s2, dp);
        
        int op1 = 1 + solve(i, j - 1, s1, s2, dp);  // insert
        int op2 = 1 + solve(i - 1, j, s1, s2, dp);  // remove
        int op3 = 1 + solve(i - 1, j - 1, s1, s2, dp); // replace  
        return dp[i][j] = min(op1, min(op2, op3));
    }
  
  public:
    int editDistance(string str1, string str2) {
        int n1 = str1.length();
        int n2 = str2.length();
        vector<vector<int>> dp(n1, vector<int> (n2, -1));
        return solve(n1 - 1, n2 - 1, str1, str2, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends