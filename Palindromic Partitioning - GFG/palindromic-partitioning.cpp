//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

bool isPalindrome(string& s){
    for(int i = 0, j = s.length()-1; i < j; i++, j--){
        if(s[i] != s[j])
            return false;
    }
    return true;
}

class Solution{
private:
    int solve(int i, string& str, vector<int> &dp){
        if(i == str.length())
            return 0;
        if(dp[i] != -1)
            return dp[i];
        
        int ans = 1000;
        string temp = "";
        for(int j = i; j < str.length(); j++)
        {
            temp.push_back(str[j]);
            if(isPalindrome(temp))
                ans = min(ans, 1 + solve(j+1, str, dp));
        }
        
        return dp[i] = ans;
    }

public:
    int palindromicPartition(string str)
    {
        vector<int> dp(str.length(), -1);
        return solve(0, str, dp) - 1;
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