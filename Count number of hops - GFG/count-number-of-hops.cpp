//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        int MOD = 1e9+7;
        
        vector<long long> dp(n + 1, 0);
    
        // base case
        dp[n] = 1;
        
        for(int i = n - 1; i >= 0; i--)
        {
            if(i + 1 <= n) dp[i] = (dp[i] + dp[i + 1]) % MOD;
            if(i + 2 <= n) dp[i] = (dp[i] + dp[i + 2]) % MOD;
            if(i + 3 <= n) dp[i] = (dp[i] + dp[i + 3]) % MOD;
        }
        
        return dp[0];
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends