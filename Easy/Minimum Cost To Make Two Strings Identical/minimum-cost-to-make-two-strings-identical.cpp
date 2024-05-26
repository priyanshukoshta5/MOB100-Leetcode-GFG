//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    int solve(int i, int j, string &x, string &y, int costX, int costY, vector<vector<int>> &dp){
        if(i == -1 && j == -1)
            return 0;
        if(i == -1)
            return (costY * (j + 1));
        if(j == -1)
            return (costX * (i + 1));
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(x[i] == y[j])
            return dp[i][j] = solve(i - 1, j - 1, x, y, costX, costY, dp);
        
        return dp[i][j] = min(costX + solve(i - 1, j, x, y, costX, costY, dp), 
                              costY + solve(i, j - 1, x, y, costX, costY, dp));
    }

  public:
    int findMinCost(string x, string y, int costX, int costY) {
        vector<vector<int>> dp(x.length(), vector<int> (y.length(), -1));
        return solve(x.length() - 1, y.length() - 1, x, y, costX, costY, dp);
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;

        int costX, costY;
        cin >> costX >> costY;

        Solution ob;
        cout << ob.findMinCost(x, y, costX, costY);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends