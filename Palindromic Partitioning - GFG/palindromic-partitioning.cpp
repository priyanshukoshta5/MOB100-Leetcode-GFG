//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

bool isPalindrome(string& s, int i, int j){
    while(i < j)
    {
        if(s[i] != s[j])    
            return false;
        i++;
        j--;
    }
    return true;
}

class Solution{
public:
    int palindromicPartition(string str)
    {
        int n = str.length();
        vector<int> dp(n+1, 0);
        
        for(int i = n-1; i >= 0; i--)
        {
            int ans = 1000;
            for(int j = i; j < n; j++)
            {
                if(isPalindrome(str, i, j))
                    ans = min(ans, 1 + dp[j+1]);
            }
            dp[i] = ans;
        }
        
        return dp[0] - 1;   // substract 1 as, our code also do partition at End ie dp[n]
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends