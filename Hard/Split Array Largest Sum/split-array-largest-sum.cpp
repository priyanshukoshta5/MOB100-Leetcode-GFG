//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    bool isValid(int arr[], int N, int maxSum, int K){
        int curSum = 0;
        int subArrs = 0;
        for(int i = 0; i < N; i++)
        {  
            curSum += arr[i];
            if(curSum > maxSum)
            {
                curSum = arr[i];
                subArrs++;
            }
            if(arr[i] > maxSum || subArrs > K)
                return false;
        }
        subArrs++;
        // cout<<maxSum<<" "<<K<<" "<<subArrs<<" "<<curSum<<endl;
        
        if(curSum > maxSum)
            return false;
        
        if(K >= subArrs)
            return true;
        return false;
    }
    
  public:
    int splitArray(int arr[] ,int N, int K) {
        int sum = 0;
        for(int i = 0; i < N; i++)
            sum += arr[i];
        
        int low = 1, high = sum, mid;
        int ans = sum;
        while(low <= high)
        {
            mid = low + (high - low) / 2;
            if(isValid(arr, N, mid, K))
            {
                high = mid - 1;
                ans = min(ans, mid);
            }
            else
                low = mid + 1;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends