//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        int ans = INT_MAX;
        int i = 0, j = 0;
        int cnt[3] = {0};
        while(j < S.length())
        {
            cnt[S[j] - '0']++;
            while(i < j && cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0)
            {
                ans = min(ans, j - i + 1);
                cnt[S[i] - '0']--;
                i++;
            }            
            j++;
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends