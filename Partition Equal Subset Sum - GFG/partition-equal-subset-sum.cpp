//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    bool subsetSum(int ind, int sum, int arr[], vector<vector<int>> &dp){
        if(sum == 0)
            return true;
        if(ind < 0)
            return false;
        if(dp[ind][sum] != -1)
            return dp[ind][sum];
        
        bool notTake = subsetSum(ind - 1, sum, arr, dp);
        bool take = false;
        if(arr[ind] <= sum)
            take = subsetSum(ind - 1, sum - arr[ind], arr, dp);
        
        return dp[ind][sum] = take | notTake;
    }
    
public:
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i = 0; i < N; i++)
            sum += arr[i];
            
        if(sum % 2 != 0)
            return false;
            
        vector<vector<int>> dp(N, vector<int> (sum / 2 + 1, -1));
        return subsetSum(N - 1, sum / 2, arr, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends