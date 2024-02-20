//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
public:
    int wordBreak(int n, string s, vector<string> &dictionary) {
        int len = s.length();
        
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        
        int dp[len + 1] = {0};
        dp[len] = 1;  // base case
        
        for(int i = len - 1; i >= 0; i--)
        {
            string temp = "";
            for(int j = i; j < len; j++)
            {
                temp.push_back(s[j]);
                if(dp[i + temp.length()] == 1 && dict.find(temp) != dict.end())
                {
                    dp[i] = 1;
                    break;
                }
            }
        }
        
        return dp[0];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends