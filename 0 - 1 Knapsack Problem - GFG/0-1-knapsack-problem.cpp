//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    private:
    int solve(int W, int wt[], int val[], int i, vector<vector<int>> &dp){
        if(i < 0)
            return 0;
        
        if(dp[W][i] != -1)
            return dp[W][i];
        
        // Not take i
        int res = solve(W, wt, val, i-1, dp);
        
        // Take i
        if(wt[i] <= W)
            res = max(res, val[i] + solve(W-wt[i], wt, val, i-1, dp));
            
        return dp[W][i] = res;
    }
    
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>> dp(W+1, vector<int> (n, -1));
        return solve(W, wt, val, n-1, dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends