//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        if(k == 1)
            return 0;
        
        long long int ans = 0;
        long long int val = 1;
        int i = 0;
        while(i < n && a[i] >= k)
            i++;
        for(int j = i; j < n; j++)
        {
            val = val * a[j];
            if(val >= k)
            {
                while(i <= j && val >= k)
                {
                    ans = ans + (j - i);
                    val = val / a[i];
                    i++;
                }
            }
        }
        while(i < n)
        {
            ans = ans + (n - i);
            i++;
        }
        
        return ans++;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends