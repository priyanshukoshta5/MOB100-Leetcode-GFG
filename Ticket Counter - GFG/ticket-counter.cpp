//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int K) {
        int low = 1, high = N;
        int leftRight = true;
        while((high-low+1) > K)
        {
            if(leftRight == true)
            {
                low += K;
                leftRight = false;
            }
            else
            {
                high -= K;
                leftRight = true;
            }
        }
        
        if(leftRight == true)
            return high;
        return low;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends