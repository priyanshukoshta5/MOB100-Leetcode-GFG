//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        vector<pair<int,int>> stocks;   // {price, cnt}
        for(int i = 0; i < n; i++)
            stocks.push_back({price[i], i + 1});
            
        sort(stocks.begin(), stocks.end());
        
        int ans = 0;
        int cur = 0;
        while(cur < n && stocks[cur].first <= k)
        {
            int cnt = min(stocks[cur].second, k / stocks[cur].first);
            int sum = stocks[cur].first * cnt;
            k = k - sum;
            ans += cnt;
            cur++;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends