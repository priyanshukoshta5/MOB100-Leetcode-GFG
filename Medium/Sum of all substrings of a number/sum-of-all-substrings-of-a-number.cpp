//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    private:
    int MOD = 1e9+7;
    
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        int n = s.length();
        
        vector<long long> ans(n, 0);
        for(int i = 0; i < n; i++)
            ans[i] = ((i + 1) * (s[i] - '0')) % MOD;
            
        // for(long long a: ans)
        //     cout<<a<<" ";
        // cout<<endl;
        
        long long res = 0;
        long long temp = 0;
        for(int i = 0; i < n; i++)
        {
            temp = (temp * 10 + ans[i]) % MOD;
            // cout<<temp<<" ";
            res = (res + temp) % MOD;
        }
        // cout<<endl;
        
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}

// } Driver Code Ends