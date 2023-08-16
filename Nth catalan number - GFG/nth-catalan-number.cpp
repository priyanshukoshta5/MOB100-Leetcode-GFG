//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    int MOD = 1e9+7;
    
    public:
    //Function to find the nth catalan number.
    int findCatalan(int n) 
    {
        if(n == 0)
            return 1;
            
        vector<long> prev(n+1, 0);
        for(int i = 1; i <= n; i++)
            prev[i] = 1;
            
        for(int open = 1; open <= n; open++)
        {
            vector<long> cur(n+1, 0);
            for(int close = open; close <= n; close++)
            {
                long case1 = prev[close];
                long case2 = cur[close - 1];
                cur[close] = (case1 + case2) % MOD;
            }
            prev = cur;
        }
        
        return prev[n];
    }
};


//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends