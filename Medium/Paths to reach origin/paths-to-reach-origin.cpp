//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    int MOD = 1e9+7;
    int ways(int x, int y)
    {
        vector<vector<long long>> dp(x + 1, vector<long long> (y + 1, 0));
        dp[0][0] = 1;
        for(int i = 0; i <= x; i++)
        {
            for(int j = 0; j <= y; j++)
            {
                if(i > 0)   dp[i][j] += dp[i - 1][j];
                if(j > 0)   dp[i][j] += dp[i][j - 1];
                dp[i][j] %= MOD;
            }
        }
        return int(dp[x][y]);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<<ob.ways(x,y)<<endl;
    }
	return 0;
}

// } Driver Code Ends