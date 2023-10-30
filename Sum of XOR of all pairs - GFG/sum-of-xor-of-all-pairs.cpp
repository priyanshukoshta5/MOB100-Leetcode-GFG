//{ Driver Code Starts
// An efficient C++ program to compute 
// sum of bitwise OR of all pairs
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
    	vector<int> bitsCount(32, 0);
    	for(int i = 0; i < n; i++)
    	{
    	    int val = arr[i];
    	    for(int b = 0; b < 32; b++)
    	    {
    	        bitsCount[b] += ((val >> b) & 1);
    	    }
    	}
    	
    	long long int ans = 0;
    	for(int i = 0; i < 32; i++)
    	{
    	    long long int one = bitsCount[i];
    	    long long int zero = n - one;
    	    ans = ans + (pow(2, i) * one * zero);
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
	 int n ;
	 cin>>n;
	 int arr[n+1];
	 for( int i=0;i<n;i++)
	    cin>>arr[i];
	 Solution ob;
	 cout<<ob.sumXOR(arr, n)<<endl;
	}	
	return 0;
}

// } Driver Code Ends