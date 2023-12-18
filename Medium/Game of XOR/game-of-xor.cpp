//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int gameOfXor(int N , int A[]) {
        if((N % 2) == 0)
            return 0;
        
        int ans = 0;
        
        for(int i = 0; i < N; i++)
        {
            int reps = (i + 1) * (N - i);
            if((reps % 2) == 1)
                ans = ans ^ A[i];
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        for(int i=0 ; i<N ; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.gameOfXor(N,A) << endl;
    }
    return 0;
}
// } Driver Code Ends