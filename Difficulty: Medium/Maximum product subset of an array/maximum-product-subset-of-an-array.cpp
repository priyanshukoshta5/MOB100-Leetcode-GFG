//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        int n = arr.size();
        int MOD = 1e9+7;

        long long int ans = -1;
        long long int maxNeg = INT_MIN;
        long long int posProd = 1;
        long long int negProd = 1;
        bool posFlag = false, negFlag = false, zeroFlag = false;
        int negCnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(arr[i] == 0)
                zeroFlag = true;
            else if(arr[i] > 0)
            {
                posProd = (posProd * 1LL * arr[i]) % MOD;
                posFlag = true;
            }
            else
            {
                negProd = (negProd * 1LL * arr[i]) % MOD;
                maxNeg = max(maxNeg, 1LL * arr[i]);
                negFlag = true;
                negCnt++;
            }
        }
        
        if(posFlag == false && negFlag == false)
            return 0;
        else if(posFlag == false)
        {
            if(negProd > 0)
                return negProd;
            if(negCnt == 1)
            {
                if(zeroFlag == true)
                    return 0;
                else
                    return maxNeg;
            }
            else if(negCnt % 2 == 0)
                return negProd;
            else
                return (negProd * 1LL / maxNeg) % MOD;
        }
        else if(negFlag == false)
            return posProd;
        
        if(negProd < 0)
            negProd = (negProd * 1LL / maxNeg) % MOD;
        
        ans = max(ans, (posProd * negProd) % MOD);
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends