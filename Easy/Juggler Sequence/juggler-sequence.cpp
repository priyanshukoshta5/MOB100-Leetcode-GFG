//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<long long> jugglerSequence(long long n) {
        vector<long long> seq;
        seq.push_back(n);
        while(seq.back() != 1)
        {
            if(seq.back() % 2 == 0)
                seq.push_back(sqrt(seq.back()));
            else
                seq.push_back(sqrt(pow(seq.back(), 3)));
        }
        return seq;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        Solution ob;
        vector<long long> ans = ob.jugglerSequence(n);
        for (long long u : ans)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends