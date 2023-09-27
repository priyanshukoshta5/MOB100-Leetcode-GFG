//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function teamplate for C++

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        vector<int> ans = {0, 0};
        
        int minDiff = INT_MAX;
        
        for(int i = 0; i < n; i++)
        {
            int j = lower_bound(brr, brr + m, x - arr[i]) - brr;
            
            if(j < m)
            {
                int sum = arr[i] + brr[j];
                if(minDiff > abs(x - sum))
                {
                    minDiff = abs(x - sum);
                    ans[0] = arr[i];
                    ans[1] = brr[j];
                }
            }
            
            if(j > 0)
            {
                int sum = arr[i] + brr[j - 1];
                if(minDiff > abs(x - sum))
                {
                    minDiff = abs(x - sum);
                    ans[0] = arr[i];
                    ans[1] = brr[j - 1];
                }
            }
            
            // cout<<minDiff<<" : "<<ans[0]<<" "<<ans[1]<<endl;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    }
    return 0;
}

// } Driver Code Ends