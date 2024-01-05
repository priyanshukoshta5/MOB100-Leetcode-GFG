//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
0	1	2	3	4	5	6	7	8	9	10
1	2	1+2	5	8   13	21	34	55	89	144
*/

class Solution{
private:
    int MOD = 1e9+7;
    
public:
	int TotalWays(int N)
	{
	    long long int a = 1, b = 1, c;
	    for(int i = 1; i <= N; i++)
	    {
	        c = (a + b) % MOD;
	        a = b; 
	        b = c;
	    }
	    long long int ans = c * c;
	    return ans % MOD;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends