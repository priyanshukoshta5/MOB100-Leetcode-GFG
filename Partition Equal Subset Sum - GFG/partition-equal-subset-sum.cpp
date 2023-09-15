//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i = 0; i < N; i++)
            sum += arr[i];
            
        if(sum % 2 != 0)
            return false;
            
        int target = sum / 2;
        vector<vector<bool>> dp(N, vector<bool> (target + 1, false));
        
        // base cases
        for(int i = 0; i < N; i++)
            dp[i][0] = true;
        for(int s = 1; s <= target; s++)
            dp[0][s] = false;
        
        for(int i = 1; i < N; i++)
        {
            for(int s = 1; s <= target; s++)
            {
                bool notTake = dp[i - 1][s];
                bool take = false;
                if(arr[i] <= s)
                    take = dp[i - 1][s - arr[i]];
                
                dp[i][s] = take | notTake;
            }
        }
        
        return dp[N - 1][target];
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