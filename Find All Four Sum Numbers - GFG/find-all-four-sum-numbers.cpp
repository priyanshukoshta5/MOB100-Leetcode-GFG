//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> ans;
        
        for(int q1 = 0; q1 < n; q1++)
        {
            for(int q2 = q1 + 1; q2 < n; q2++)
            {
                int q3 = q2 + 1, q4 = n - 1;
                while(q3 < q4)
                {
                    int rem = k - arr[q1] - arr[q2] - arr[q3];
                    
                    if(rem == arr[q4])
                    {
                        vector<int> res = {arr[q1], arr[q2], arr[q3], arr[q4]};
                        ans.push_back(res);
                    }
                    
                    if(rem > arr[q4])
                    {
                        int cur = arr[q3];
                        while(q3 < q4 && arr[q3] == cur)
                            q3++;
                    }
                    else
                    {
                        int cur = arr[q4];
                        while(q3 < q4 && arr[q4] == cur)
                            q4--;
                    }
                }
                
                int cur = arr[q2];
                while(q2 < n && arr[q2] == cur)
                    q2++;
                q2--;
            }
            
            int cur = arr[q1];
            while(q1 < n && arr[q1] == cur)
                q1++;
            q1--;
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends