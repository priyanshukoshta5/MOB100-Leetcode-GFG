//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int ans = -1;
        int uniqueChars = 0;
        int i = 0, j = 0;
        vector<int> freq(26, 0);
        
        while(j < s.length())
        {
            freq[s[j] - 'a']++;
            if(freq[s[j] - 'a'] == 1)   // it is first occurance of s[j] left
                uniqueChars++;
                
            while(i <= j && uniqueChars > k)
            {
                freq[s[i] - 'a']--;
                if(freq[s[i] - 'a'] == 0)   // there is no occurance of s[i] left
                    uniqueChars--;
                i++;
            }
            
            if(uniqueChars == k)
                ans = max(ans, j - i + 1);
                
            j++;
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
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends