//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int countPS(string &s) {
        // code here
        int i, n = s.size(), ans = 0;
        for(i = 0; i < n; i++)
        {
            int l = i - 1, r = i + 1;
            while(l >-1 && r<n && s[l]==s[r]) 
                ans++, l--, r++;
            if(i == 0 || s[i - 1] != s[i]) 
                continue;
            l = i - 1, r = i;
            while(l >-1 && r < n && s[l] == s[r]) 
                ans++, l--, r++;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends