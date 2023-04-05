//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int N, vector<int> arr) {
        unordered_map<int,int> mp;
        for(int i: arr)
            mp[i]++;
            
        if(mp.find(1) != mp.end())
        {
            if(mp[1] == 1)
                return N-1;
            return N;
        }
        
        int ans = 0;
        
        for(int num: arr)
        {
            if(mp[num] > 1)
            {
                ans++;
                continue;
            }
            for(int i=2; i<=sqrt(num); i++)
            {
                if(num%i == 0)
                {
                    if(mp.find(i)!=mp.end() || mp.find(num/i)!=mp.end())
                    {
                        ans++;
                        break;
                    }
                }
            }
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
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends