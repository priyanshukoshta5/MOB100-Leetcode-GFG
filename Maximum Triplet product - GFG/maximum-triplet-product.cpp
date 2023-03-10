//{ Driver Code Starts
//Initial Template for CPP

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long maxTripletProduct(long long arr[], int n)
    {
    	// Complete the function
    	priority_queue<long long> maxH;     // to get 2 minimum elements
    	priority_queue<long long, vector<long long>, greater<long long>> minH;  // to get 3 maximum elements
    	for(int i=0; i<n; i++)
    	{
    	    minH.push(arr[i]);
    	    maxH.push(arr[i]);
    	    if(maxH.size() > 2)
    	        maxH.pop();
    	    if(minH.size() > 3)
    	        minH.pop();
    	}
    	
    // 	while(!maxH.empty())
    // 	{
    // 	    cout<<maxH.top()<<" ";
    // 	    maxH.pop();
    // 	}
    // 	cout<<endl;
    
        long long l2 = maxH.top(); maxH.pop();
        long long l1 = maxH.top(); maxH.pop();
    	
    // 	while(!minH.empty())
    // 	{
    // 	    cout<<minH.top()<<" ";
    // 	    minH.pop();
    // 	}
    // 	cout<<endl;
    
        long long h3 = minH.top(); minH.pop();
        long long h2 = minH.top(); minH.pop();
        long long h1 = minH.top(); minH.pop();
        
        long long ans = INT_MIN;
        ans = max(ans, h1*h2*h3);
        ans = max(ans, h1*l1*l2);
        
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
	    int n,i;
	    cin>>n; long long arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    Solution ob;
	    cout <<ob.maxTripletProduct(arr, n);
	    cout<<"\n";
	}
    return 0;
}
// } Driver Code Ends