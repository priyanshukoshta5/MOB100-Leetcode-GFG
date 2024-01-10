//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    unordered_map<int, int> pos;
	    pos[0] = -1;
	    int ans = 0;
	    int sum = 0;
	    for(int i = 0; i < n; i++)
	    {
	        sum += arr[i];
	        if(sum % k == 0)
	            ans = max(ans, i + 1);
	        else if(sum > 0)
	        {
	            if(pos.find(sum % k) == pos.end())
	                pos[sum % k] = i;
	            else
	                ans =  max(ans, i - pos[sum % k]);
	        }
	        else
	        {
	            if(pos.find(k + sum % k) == pos.end())
	                pos[k + sum % k] = i;
	            else 
	                ans =  max(ans, i - pos[k + sum % k]);
	        }
	       // cout<<i<<" "<<sum<<" "<<(sum % k)<<" "<<(k + sum % k)<<" "<<ans<<endl;
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
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends