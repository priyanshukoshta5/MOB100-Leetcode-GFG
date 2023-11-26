//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    void doIt(int n, vector<int> &ans){
        if(n <= 0)
        {
            ans.push_back(n);
            return;
        }
        ans.push_back(n);
        doIt(n - 5, ans);
        ans.push_back(n);
    }
    
public:
    vector<int> pattern(int N){
        vector<int> ans;
        doIt(N, ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends