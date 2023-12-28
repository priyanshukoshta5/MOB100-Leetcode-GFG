//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
private:
    bool solve(int i, int j, int n, int m, string &wild, string &pattern, vector<vector<int>> &dp){
        if(i == n && j == m)
            return true;
        if(i == n || j == m || (wild[i] != '?' && wild[i] != '*' && wild[i] != pattern[j]))
            return false;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        bool res = false;
        
        if(wild[i] == pattern[j] || wild[i] == '?')
            res = res || solve(i + 1, j + 1, n, m, wild, pattern, dp);
        else if(wild[i] == '*')
        {
            for(int k = j; k <= m; k++)
            {
                res = res || solve(i + 1, k, n, m, wild, pattern, dp);
                if(res == true)
                    break;
            }
        }
        
        return dp[i][j] = res;
    }
    
public:
    bool match(string wild, string pattern)
    {
        int n = wild.length();
        int m = pattern.length();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(0, 0, n, m, wild, pattern, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends