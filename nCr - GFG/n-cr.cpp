//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int MOD = 1e9+7;
   
public:
    int nCr(int n, int r){
        if(r > n)
            return 0;
        if(n == 1)
            return 1;
        
        vector<long> prev = {1,1};
        vector<long> cur;
        
        for(int i = 2; i <= n; i++)
        {
            cur.push_back(1);
            for(int j = 1; j < i; j++)
            {
                cur.push_back(prev[j-1] + prev[j]);
                cur.back() = cur.back() % MOD;
            }
            cur.push_back(1);
            prev = cur;
            cur.clear();
        }
        
        return prev[r];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends