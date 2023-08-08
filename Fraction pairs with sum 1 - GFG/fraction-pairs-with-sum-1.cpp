//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countFractions(int n, int numerator[], int denominator[])
    {
        vector<pair<int,int>> arr;
        for(int i = 0; i < n; i++)
        {
            int gcd = __gcd(numerator[i], denominator[i]);
            arr.push_back({numerator[i] / gcd, denominator[i] / gcd});
        }
        
        map<pair<int,int>, int> mp;
        int ans = 0;
        for(auto i: arr)
        {
            int nume = i.first;
            int deno = i.second;
            if(mp.find({deno - nume, deno}) != mp.end())
                ans += mp[{deno - nume, deno}];
            mp[{nume, deno}]++;
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
        int n;
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends