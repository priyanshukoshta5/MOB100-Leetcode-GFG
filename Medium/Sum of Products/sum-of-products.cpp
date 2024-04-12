//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    long long pairAndSum(int n, long long arr[]) {
        vector<long long> freq(32, 0);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < 32; j++)
            {
                if(((arr[i] >> j) & 1) == 1)
                    freq[j]++;
            }
        }
        
        long long ans = 0;
        for(int i = 0; i < 32; i++)
        {
            if(freq[i] <= 1)
                continue;
            
            long long temp = (freq[i] * (freq[i] - 1)) / 2;
            ans = ans + (temp * pow(2, i));
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        long long Arr[N];
        for (int i = 0; i < N; i++) {
            cin >> Arr[i];
        }
        Solution ob;
        cout << ob.pairAndSum(N, Arr) << endl;
    }
    return 0;
}
// } Driver Code Ends