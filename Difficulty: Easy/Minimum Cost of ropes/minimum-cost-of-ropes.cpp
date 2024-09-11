//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        int n = arr.size();
        if(n == 1)
            return 0;
        
        priority_queue<int, vector<int>, greater<int>> minH(arr.begin(), arr.end());
        
        long long ans = 0;
        while(minH.size() > 1)
        {
            long long a = minH.top(); minH.pop();
            long long b = minH.top(); minH.pop();
            ans += (a + b);
            minH.push(a + b);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        long long num;
        vector<long long> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
    }
    return 0;
}

// } Driver Code Ends