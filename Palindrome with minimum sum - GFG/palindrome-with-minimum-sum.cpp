//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumSum(string s) {
        int i = 0, j = s.length()-1;
        char prev = '.';
        int ans = 0;
        while(i <= j)
        {
            if(i == j)
            {
                if(s[i] != '?' && prev != '.')
                    ans += abs(s[i] - prev);
            }
            else if(s[i] == '?' || s[j] == '?')
            {
                if(s[i] == '?' && s[j] != '?')
                {
                    if(prev != '.')
                        ans = ans + 2 * abs(s[j] - prev);
                    prev = s[j];
                }
                else if(s[i] != '?' && s[j] == '?')
                {
                    if(prev != '.')
                        ans = ans + 2 * abs(s[i] - prev);
                    prev = s[i];
                }
                
            }
            else if(s[i] == s[j])
            {
                if(prev != '.')
                    ans = ans + 2 * abs(s[i] - prev);
                prev = s[i];
            }
            else
                return -1;
                
            i++;
            j--;
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
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends