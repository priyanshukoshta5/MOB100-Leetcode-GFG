//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        int low = lower_bound(arr, arr + n, k) - arr;
        int high = upper_bound(arr, arr + n, k) - arr;
        
        int ans = -1;
        if(low == -1 || low == high) low--;
        if(high == n) high--;
        
        // cout<<arr[low]<<" "<<arr[high]<<endl;
        
        if(abs(arr[low] - k) < abs(arr[high] - k))
            ans = arr[low];
        else
            ans = arr[high];
        
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
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends