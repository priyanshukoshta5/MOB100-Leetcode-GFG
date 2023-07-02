//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
    public:
    int setSetBit(int x, int y, int l, int r){
        vector<int> a(32, 0), b(32, 0);
        for(int i = 0; i < 32; i++)
        {
            a[i] = (x>>i) & 1;
            b[i] = (y>>i) & 1;
        }
            
        for(int i = l-1; i < r; i++)
            a[i] = a[i] | b[i];
            
        long long int val = 0;
        for(int i = 0; i < 32; i++)
            val = val + a[i] * pow(2,i);
        
        return val;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int x, y, l, r;
        cin>>x>>y>>l>>r;
        
        Solution ob;
        cout<<ob.setSetBit(x, y, l, r)<<"\n";
    }
    return 0;
}
// } Driver Code Ends