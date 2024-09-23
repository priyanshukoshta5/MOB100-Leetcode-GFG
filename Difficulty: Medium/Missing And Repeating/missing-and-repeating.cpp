//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        vector<int> freq(arr.size() + 1, 0);
        vector<int> ans;
        for(int i: arr)
        {
            freq[i]++;
            if(freq[i] == 2)
                ans.push_back(i);
        }
        for(int i = 1; i <= arr.size(); i++)
        {
            if(freq[i] == 0)
            {
                ans.push_back(i);
                break;
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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends