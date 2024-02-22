//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    private:
    int MOD = 1e9+7;
    
    int solve(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        if(j < 0)
            return 1;
        if(i < 0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        // take
        long long take = 0;
        if(s[i] == t[j])
            take = solve(i - 1, j - 1, s, t, dp);
        
        // notTake
        long long notTake = solve(i - 1, j, s, t, dp);
        
        return dp[i][j] = (take + notTake) % MOD;
    }
    
    public:
    int subsequenceCount(string s, string t)
    {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(n - 1, m - 1, s, t, dp);
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends