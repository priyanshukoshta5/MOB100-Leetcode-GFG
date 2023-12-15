//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    int MOD = 1e9+7;
		int nthPoint(int n){
		    if(n == 1)
		        return 1;
		    if(n == 2)
		        return 2;
		    
		    long long a = 1;
		    long long b = 2;
		    for(int i = 3; i <= n; i++)
		    {
		        long long c = (a + b) % MOD;
		        a = b;
		        b = c;
		    }
		    return b;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends