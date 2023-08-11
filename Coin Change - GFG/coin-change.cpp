//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    long long int coinChange(int coins[], int ind, int T, vector<vector<long long int>>& dp){
        if(ind == 0)
            return (T % coins[0] == 0);
        
        if(dp[ind][T] != -1)
            return dp[ind][T];
            
        long notTaken = coinChange(coins, ind - 1, T, dp);
        
        long taken = 0;
        if(coins[ind] <= T)
            taken = coinChange(coins, ind, T - coins[ind], dp);
            
        return dp[ind][T] = notTaken + taken;
    }
    
  public:
    long long int count(int coins[], int N, int sum) {
        vector<vector<long long int>> dp(N, vector<long long int>(sum + 1,-1));
        return coinChange(coins, N-1, sum, dp);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends