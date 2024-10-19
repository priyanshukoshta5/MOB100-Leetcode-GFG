//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

#include<bits/stdc++.h>

class Solution {
  public:
    string roundToNearest(string str) {
        int n = str.length();
        if(str[n - 1] <= '5')
        {
            str[n - 1] = '0';
            return str;
        }
        
        bool rem = true;
        str[n - 1] = '0';
        for(int i = n - 2; i >= 0; i--)
        {
            if(str[i] == '9')
            {
                str[i] = '0';
                rem = true;
            }
            else
            {
                str[i] = (str[i] + 1);
                rem = false;
                break;
            }
        }
        
        if(rem == true)
        {
            reverse(str.begin(), str.end());
            str.push_back('1');
            reverse(str.begin(), str.end());
        }
        return str;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends