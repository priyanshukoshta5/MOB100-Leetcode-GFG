//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
private:
    int solve(int ind, int total, vector<int> &cost, vector<vector<int>> &dp){
        if(ind == cost.size())
            return 0;
        if(dp[ind][total] != -1)
            return dp[ind][total];
        
        int take = 0;
        if(total >= cost[ind])
        {
            int newTotal = total - cost[ind];
            newTotal += 9 * cost[ind] / 10;
            take = 1 + solve(ind + 1, newTotal, cost, dp);
        }
        
        int notTake = solve(ind + 1, total, cost, dp);
        
        return dp[ind][total] = max(take, notTake);
    }

public:
    int max_courses(int n, int total, vector<int> &cost)
    {
        vector<vector<int>> dp(n, vector<int> (total + 1, -1));
        return solve(0, total, cost, dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        cout<<ob.max_courses(n,k,arr)<<endl;
    }
}
// } Driver Code Ends