//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
    int noConseBits(int n) {
        vector<int> bin;
        while(n>0)
        {
            bin.push_back(n%2);
            n = n/2;
        }
        // for(int x: bin)
        //     cout<<x;
        // cout<<endl;
        
        int i = bin.size()-1;
        int streak = 0;
        while(i>=0)
        {
            if(bin[i] == 1)
                streak++;
            else
                streak = 0;
            if(streak == 3)
            {
                streak = 0;
                bin[i] = 0;
            }
            i--;
        }
        // for(int x: bin)
        //     cout<<x;
        // cout<<endl;    
        
        int ans = 0;
        for(i=0; i<bin.size(); i++)
            ans += pow(2,i)*bin[i];
            
            
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        int ans = sol.noConseBits(n);
        cout << ans << '\n';
    }

    return 0;
}

// } Driver Code Ends