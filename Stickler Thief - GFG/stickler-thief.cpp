//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        vector<int> dp(n + 2, 0);
        
        // base case
        dp[n] = 0;
        dp[n + 1] = 0;
        
        for(int ind = n - 1; ind >= 0; ind--)
        {
            // loot current house
            int loot = arr[ind] + dp[ind + 2];
            
            // do not loot current house
            int notLoot = dp[ind + 1];
            
            dp[ind] = max(loot, notLoot);
        }
        
        return dp[0];
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
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends