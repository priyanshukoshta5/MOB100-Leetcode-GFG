//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if(start == end)
            return 0;
        
        queue<pair<int, int>> q;
        vector<int> dist(100000, 1e9);
        q.push({start, 0});
        dist[start] = 0;
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            
            int num1 = it.first;
            int steps = it.second;
            
            for(int i: arr)
            {
                int num2 = i;
                int val = (num1 * num2) % 100000;
                
                if(dist[val] > (steps + 1))
                {
                    if(val == end)
                        return steps + 1;
                        
                    dist[val] = steps + 1;
                    q.push({val, steps + 1});
                }
            }
        }
        
        return -1;
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
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends