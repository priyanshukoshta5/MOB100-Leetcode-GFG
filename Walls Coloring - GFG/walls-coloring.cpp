//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
private:
    int solve(vector<vector<int>>& colors, int n, int prevCol, vector<vector<int>>& dp)
    {
        if(n == -1)
            return 0;
            
        if(dp[n][prevCol] != -1)
            return dp[n][prevCol];
            
        int ans = INT_MAX;
        for(int i=0; i<3; i++) 
            if(i != prevCol)
                ans = min(ans, colors[n][prevCol] + solve(colors, n-1, i, dp));
                
        return dp[n][prevCol] = ans;
    }
    
public:
    int minCost(vector<vector<int>> &colors, int N) {
        // Write your code here.
        vector<vector<int>> dp(N, vector<int> (3, -1));
        
        int res = INT_MAX;
        for(int i=0; i<3; i++)
            res = min(res, solve(colors, N-1, i, dp));
            
        return res;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends