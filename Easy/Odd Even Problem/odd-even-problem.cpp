//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
        map<char, int> freq;
        for(char ch: s)
            freq[ch]++;
            
        int x = 0, y = 0;
        for(auto i: freq)
        {
            if((i.first - 'a' + 1) % 2 == 0 && i.second % 2 == 0)
                x++;
            else if((i.first - 'a' + 1) % 2 == 1 && i.second % 2 == 1)
                y++;
            
        }
        
        return (x + y) % 2 == 0 ? "EVEN" : "ODD";
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends