//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

// ~Editorial

class Solution {
  public:
    int minSteps(int d) {
        int steps = 0 , count = 0;
        
        while(count < d)
        {
            steps++;
            count += steps;
            // cout<<count<<" ";
        }
        
        while((count - d) % 2 != 0)
        {
            steps++;
            count += steps;
            // cout<<count<<" ";
        }
        
        return steps;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int d;
        cin >> d;

        Solution ob;
        cout << ob.minSteps(d) << "\n";
    }
    return 0;
}
// } Driver Code Ends