//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        vector<int> jumps(leaves+1, 0);
        for(int i=0; i<N; i++)
        {
            if(frogs[i] == 1)
                return 0;
            if(frogs[i]<=leaves && jumps[frogs[i]] == 0)
            {
                for(int j=frogs[i]; j<=leaves; j+=frogs[i])
                    jumps[j] = 1;
            }
        }
        
        int cnt = 0;
        for(int i=1; i<=leaves; i++)
            if(jumps[i] == 0)
                cnt++;
                
        return cnt;
    }
};


//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, leaves;
        cin >> N >> leaves;
        int frogs[N];
        for (int i = 0; i < N; i++) {
            cin >> frogs[i];
        }

        Solution ob;
        cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    }
}
// } Driver Code Ends