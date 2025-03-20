//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// } Driver Code Ends

class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        vector<int> dp(n + 2, 0);
        
        // base case
        dp[n] = 0;
        dp[n + 1] = 0;
        
        for(int ind = n - 1; ind >= 0; ind--)
        {
            // loot current house
            int loot = arr[ind] + dp[ind + 2];
            
            // do not loot current house
            int notLoot = dp[ind + 1];
            
            dp[ind] = max(loot, notLoot);
        }
        
        return dp[0];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends