//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    int MOD = 1e9+7;
public:
    long long sequence(int n){
        long long ans = 0;
        int num = 1;
        for(int i = 1; i <= n; i++)
        {
            long long temp = 1;
            for(int j = 0; j < i; j++)
            {
                temp = temp * num;
                temp = temp % MOD;
                num++;
            }
            ans = ans + temp;
            ans = ans % MOD;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends