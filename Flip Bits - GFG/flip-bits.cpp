//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        int total1 = count(a, a+n, 1);
        
        int ans = total1;
        
        int i = 0, j = 0;
        int cnt1 = 0, cnt0 = 0;
        while(j < n)
        {
            if(a[j] == 0) cnt0++;
            else cnt1++;
            
            while(i <= j && cnt1 > cnt0)
            {
                if(a[i] == 0) cnt0--;
                else cnt1--;
                i++;
            }
            
            ans = max(ans, cnt0 + (total1 - cnt1));
            
            j++;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends