//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  private:
    int MOD = 1e9+7;
    
  public:
    int nthFibonacci(int n){
        if(n <= 2)
            return 1;
        
        long a = 1;
        long b = 1;
        long c;
        
        for(int i = 3; i <= n; i++)
        {
            c = (a + b) % MOD;
            a = b;
            b = c;
        }
        
        return c;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends