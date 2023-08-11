//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
  public:
    long long int count(int coins[], int N, int sum) {
        vector<vector<long long int>> dp(N, vector<long long int>(sum + 1, 0));
        for(int s = 0; s <= sum; s++)
            if(s % coins[0] == 0)
                dp[0][s] = 1;
        
        for(int i = 1; i < N; i++)
        {
            for(int s = 0; s <= sum; s++)
            {
                long long int notTake = dp[i - 1][s];
                long long int take = 0;
                if(coins[i] <= s)
                    take = dp[i][s - coins[i]];
                    
                dp[i][s] = notTake + take;
            }
        }
        
        return dp[N-1][sum];
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