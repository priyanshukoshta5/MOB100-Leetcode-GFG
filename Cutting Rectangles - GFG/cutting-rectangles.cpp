//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<long long int> minimumSquares(long long int L, long long int B)
    {
        long long int smallE = min(L, B);
        long long int largeE = max(L, B);
        vector<long long int> ans = {-1, -1};
        for(long long int i=1; i<=sqrt(smallE); i++)
        {
            if(smallE%i == 0)
            {
                if(largeE%i == 0 && (ans[0] == -1 || ans[1] < i))
                {
                    ans[0] = (largeE/i)*(smallE/i);
                    ans[1] = i;
                }
                
                long long int i2 = smallE/i;
                if(largeE%i2 == 0 && ans[1] < i2)
                {
                    ans[0] = (largeE/i2)*(smallE/i2);
                    ans[1] = i2;
                }
                
                // cout<<i<<" "<<i2<<endl;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long int L, B;
        cin>>L>>B;
        
        Solution ob;
        vector<long long int> ans = ob.minimumSquares(L, B);
        cout<<ans[0]<<" "<<ans[1]<<"\n";
    }
    return 0;
}
// } Driver Code Ends