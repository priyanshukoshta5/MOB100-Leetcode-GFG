//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
private:
    void dfs(int ind, vector<int> &arr, int k, vector<int> &temp, set<vector<int>> &ans){
        if(k == 0)
        {
            ans.insert(temp);
            return;
        }
        if(ind == arr.size() || arr[ind] > k)
            return;
            
        // cout<<k<<" ";
        temp.push_back(arr[ind]);
        dfs(ind + 1, arr, k - arr[ind], temp, ans);
        temp.pop_back();
        
        dfs(ind + 1, arr, k, temp, ans);
    }
    
public:
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        sort(arr.begin(), arr.end());
        set<vector<int>> ans;
        vector<int> temp;
        dfs(0, arr, k, temp, ans);
        
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
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
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends