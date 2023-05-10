//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int N,int K,vector<int> &A){
        vector<int> smallFromRight(N);
        smallFromRight[N-1] = A[N-1];
        for(int i=N-2; i>=0; i--)
            smallFromRight[i] = min(smallFromRight[i+1], A[i]);
            
        int cnt = 0;
        int largestFromLeft = A[0];
        for(int i=0; i<N-1; i++)
        {
            largestFromLeft = max(largestFromLeft, A[i]);
            if((largestFromLeft + smallFromRight[i+1]) >= K)
                cnt++;
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends