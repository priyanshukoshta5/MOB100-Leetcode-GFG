//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
private:
    bool check(int ind, int sum, int coins[], int N, vector<vector<int>> &dp){
        if(sum > 0 && (sum % 20 == 0 || sum % 24 == 0 || sum % 2024 == 0))
            return true;
        if(ind == N)
            return false;
        if(dp[ind][sum] != -1)
            return dp[ind][sum];
        
        bool flag = false;
        // notTake
        flag = flag | check(ind + 1, sum, coins, N, dp);
        
        // take
        if(flag == false && (sum + coins[ind]) <= 2024)
            flag = flag | check(ind + 1, sum + coins[ind], coins, N, dp);
        
        return dp[ind][sum] = flag;
    }

public:
    int isPossible(int N , int coins[]) 
    {
        vector<vector<int>> dp(N, vector<int> (2025, -1));
        return check(0, 0, coins, N, dp);
    }
    
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int coins[N];
        for(int i=0 ; i<N ; i++)
            cin>>coins[i];

        Solution ob;
        cout << ob.isPossible(N,coins) << endl;
    }
    return 0;
}
// } Driver Code Ends