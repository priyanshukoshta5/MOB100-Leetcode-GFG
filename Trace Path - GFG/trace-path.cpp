//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isPossible(int n, int m, string s){
        int left = 0, right = 0;
        int up = 0, down = 0;
        int l=0, u=0;
        int k = 0;
        while(k < s.length())
        {
            if(s[k] == 'L')
            {
                l--;
                left = min(left, l);
            }
            else if(s[k] == 'R')
            {
                l++;
                right = max(right, l);
            }
            else if(s[k] == 'U')
            {
                u--;
                up = min(up, u);
            }
            else if(s[k] == 'D')
            {
                u++;
                down = max(down, u);
            }
            if((right - left + 1) > m || (down - up + 1) > n)
                return 0;
            k++;
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.isPossible(n, m, s)<<endl;
    }
    return 0;
}
// } Driver Code Ends