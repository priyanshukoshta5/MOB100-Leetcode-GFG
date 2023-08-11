//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
  public:
    long long int count(int coins[], int N, int sum) {
        vector<long long int> prev(sum + 1, 0), cur(sum + 1, 0);
        for(int s = 0; s <= sum; s++)
            if(s % coins[0] == 0)
                prev[s] = 1;
        
        for(int i = 1; i < N; i++)
        {
            for(int s = 0; s <= sum; s++)
            {
                long long int notTake = prev[s];
                long long int take = 0;
                if(coins[i] <= s)
                    take = cur[s - coins[i]];
                    
                cur[s] = notTake + take;
            }
            prev = cur;
        }
        
        return prev[sum];
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