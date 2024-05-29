//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// with the help of editorial

class Solution {
  private:
    int solve(int n, bool flag, int x, int y, vector<vector<int>> &dp){
        bool ans = !flag;
        if(n == 1 || n == x || n == y)
            return flag;
            
        if(dp[n][flag] != -1)
            return dp[n][flag];
        
        if((n - x) >= 0 && solve(n - x, !flag, x, y, dp) == flag)
            ans = flag;
        
        if((n - y) >= 0 && solve(n - y, !flag, x, y, dp) == flag)
            ans = flag;
        
        if(solve(n - 1, !flag, x, y, dp) == flag)
            ans = flag;
        
        return dp[n][flag] = ans;
    }
    
  public:
    int findWinner(int n, int x, int y) {
        // code here
        vector<vector<int>> dp(n + 1, vector<int> (2, -1));
        return solve(n, true, x, y, dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        Solution obj;
        int res = obj.findWinner(n, x, y);

        cout << res << endl;
    }
}

// } Driver Code Ends