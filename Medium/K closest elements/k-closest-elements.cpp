//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        sort(arr.begin(), arr.end());
        
        int ind = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int l = ind - 1, r = ind;
        if(arr[ind] == x)
            r++;
        
        vector<int> ans;
        // cout<<ind<<" -> "<<arr[ind]<<endl;
        while(k > 0 && (l >= 0 || r < n))
        {
            if(l >= 0 && r < n)
            {
                // cout<<arr[r] - x<<" "<<x - arr[l]<<endl;
                if((arr[r] - x) <= (x - arr[l]))
                {
                    ans.push_back(arr[r]);
                    r++;
                }
                else
                {
                    ans.push_back(arr[l]);
                    l--;
                }
            }
            else if(l >= 0)
            {
                ans.push_back(arr[l]);
                l--;
            }
            else
            {
                ans.push_back(arr[r]);
                r++;
            }
            k--;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends