//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MOD = 1e9+7;
  
    vector<int> Series(int n) {
        vector<int> fib = {0, 1};
        
        if(n == 1)
            return fib;
        
        for(int i = 2; i <= n; i++)
            fib.push_back((1LL*fib[i - 2] + 1LL*fib[i - 1]) % MOD);
        
        return fib;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends