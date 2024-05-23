//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int solve(int i, int j, string &str, vector<vector<int>> &dp){
        if(i >= j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int res = 0;
        if(str[i] == str[j])
            res = solve(i + 1, j - 1, str, dp);
        else
            res = 1 + min(solve(i + 1, j, str, dp), solve(i, j - 1, str, dp));
        
        return dp[i][j] = res;
    }
    
public:
    int kPalindrome(string str, int n, int k)
    {
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solve(0, n - 1, str, dp) <= k;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.kPalindrome(str, n, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends