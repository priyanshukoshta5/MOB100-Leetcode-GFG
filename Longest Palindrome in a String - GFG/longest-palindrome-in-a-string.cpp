//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        string ans;
        ans.push_back(s[0]);
        int i = 0, start, end, len;
        
        while(i < s.length())
        {
            start = i-1;
            end = i+1;
            
            // ODD Length
            while(start >= 0 && end < s.length() && s[start] == s[end])
            {
                start--;
                end++;
            }
            len = end - start - 1;
            if(ans.length() < len)
                ans = s.substr(start+1, len);
            
            
            if((i+1) == s.length())
                break;
                
            // EVEN Length
            start = i;
            end = i+1;
            while(start >= 0 && end < s.length() && s[start] == s[end])
            {
                start--;
                end++;
            }
            len = end - start - 1;
            if(ans.length() < len)
                ans = s.substr(start+1, len);
            
            i++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends