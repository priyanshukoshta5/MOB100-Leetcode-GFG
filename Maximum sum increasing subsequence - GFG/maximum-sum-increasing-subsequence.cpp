//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	private:
	    int solve(int arr[], int n, int i, int prev, vector<vector<int>>& dp){
	        if(i == n)
	            return 0;
	        
	        if(dp[i][prev+1] != -1)
	            return dp[i][prev+1];
	        
	        // Not take
	        int notTake = solve(arr, n, i+1, prev, dp);
	        
	        // Take
	        int take = -1;
	        if(arr[i] > arr[prev])
	            take = arr[i] + solve(arr, n, i+1, i, dp);
	            
	        return dp[i][prev+1] = max(take, notTake);
	    }

	public:
    	int maxSumIS(int arr[], int n)  
    	{  
    	    vector<vector<int>> dp(n, vector<int> (n+1,-1)); // {curIndex, prevIndex};
    	    return solve(arr, n, 0, -1, dp);
    	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends