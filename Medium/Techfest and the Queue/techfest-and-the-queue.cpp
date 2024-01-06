//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
private:
    int getSumOfPowers(int n){
        int cnt = 0;
        int val = n;
        // cout<<n<<" - ";
        for(int i = 2; i <= sqrt(n); i++)
        {
            while(val % i == 0)
            {
                // cout<<i<<" ";
                val = val / i;
                cnt++;
            }
        }
        // cout<<val<<endl;
        if(val != 1)
            cnt++;
        return cnt;
    }

public:
	int sumOfPowers(int a, int b){
	    int ans = 0;
	    for(int i = a; i <= b; i++)
	        ans += getSumOfPowers(i);
	    return ans;
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends