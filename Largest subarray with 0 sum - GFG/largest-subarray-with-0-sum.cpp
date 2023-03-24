//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        int ans = 0;
        unordered_map<int, int> mp;     // presum -> smallest_index
        int presum = 0;
        for(int i=0; i<n; i++)
        {
            presum = presum+A[i];
            if(mp.find(presum) != mp.end())
                ans = max(ans, i-mp[presum]);
            else
                mp[presum] = i;
                
            if(presum == 0)
                ans = max(ans, i+1);
                
            // cout<<presum<<" ";
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
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends