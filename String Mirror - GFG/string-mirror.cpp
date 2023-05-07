//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string stringMirror(string str){
        string ans;
        ans.push_back(str[0]);
        
        for(int i=1; i<str.length(); i++)
        {
            if(str[i] < str[i-1] || (str[i] == str[i-1] && str[i] < ans[0]))
                ans.push_back(str[i]);
            else
                break;
        }
        
        int n = ans.length();
        for(int i=0; i<n; i++)
            ans.push_back(ans[n-i-1]);
        
        return ans;
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
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends