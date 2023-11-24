//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// #define ll long long
class Solution{
private:
    int MOD = 1e9+7;
    
public:
    vector<long long> nthRowOfPascalTriangle(int n) {
        vector<long long> pascal;
        pascal.push_back(1);
        for(int i = 2; i <= n; i++)
        {
            vector<long long> row(i, 1);
            for(int j = 1; j < pascal.size(); j++)
                row[j] = (pascal[j - 1] + pascal[j]) % MOD;;
            pascal = row;
        }
        return pascal;
    }
};


//{ Driver Code Starts.


void printAns(vector<long long> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends