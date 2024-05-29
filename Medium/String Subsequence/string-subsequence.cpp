//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    int MOD = 1e9+7;
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        // cout<<i<<" "<<j<<endl;
        if(j == -1)
            return 1;
        if(i == -1)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
            
        int notTake = solve(i - 1, j, s1, s2, dp) % MOD;
        int take = 0;
        if(s1[i] == s2[j])
            take = solve(i - 1, j - 1, s1, s2, dp) % MOD;
        
        return dp[i][j] = (1LL * notTake + take) % MOD;
    }
    
  public:
    int countWays(string s1, string s2) {
        vector<vector<int>> dp(s1.length(), vector<int> (s2.length(), -1));
        return solve(s1.length() - 1, s2.length() - 1, s1, s2, dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    }
}

// } Driver Code Ends