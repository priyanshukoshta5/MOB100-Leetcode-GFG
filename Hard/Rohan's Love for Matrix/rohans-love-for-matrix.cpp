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
    int firstElement(int n) {
        long long a[2][2] = {{1, 1},
                               {1, 0}};
        long long mat[2][2] = {{1, 1},
                               {1, 0}};
        
        for(int i = 2; i <= n; i++)
        {
            long long temp[2][2] = {{(mat[0][0] + mat[0][1]) % MOD, (mat[0][0]) % MOD},
                                   {(mat[0][0]) % MOD, (mat[0][1]) % MOD}};
            
            mat[0][0] = temp[0][0];
            mat[0][1] = temp[0][1];
            mat[1][0] = temp[1][0];
            mat[1][1] = temp[1][1];
        }
        
        return mat[1][0];
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
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends