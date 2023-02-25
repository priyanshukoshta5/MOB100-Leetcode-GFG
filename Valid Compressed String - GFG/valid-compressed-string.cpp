//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  private:
    bool isnumeric(char c)
    {
        if(c>='0' && c<='9')
            return true;
        return false;
    }
  public:
    int checkCompressed(string S, string T) {
        int i = 0, j = 0;
        int n = S.length();
        int m = T.length();
        int count = 0;
        
        while(i<n && j<m)
        {
            if(S[i] == T[j])
            {
                i++;
                j++;
            }
            else if(isnumeric(T[j]))
            {
                count = 0;
                while(j<m && isnumeric(T[j]))
                {
                    count = count*10;
                    count = count + (T[j]-'0');
                    j++;
                }
                // cout<<i<<" "<<j<<" "<<count<<endl;
                while(count>0 && i<n)
                {
                    i++;
                    count--;
                }
                // cout<<i<<" "<<j<<" "<<count<<endl;
            }
            else
                return 0;
        }
        
        if(i<n || j<m || count!=0)
            return 0;
        return 1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends