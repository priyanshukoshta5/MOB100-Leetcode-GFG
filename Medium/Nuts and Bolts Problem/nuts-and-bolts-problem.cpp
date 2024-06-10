//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++

map<char, int> code = {{'!', 0}, {'#', 1}, {'$', 2}, {'%', 3}, {'&', 4}, {'*', 5}, {'?', 6}, {'@', 7}, {'^', 8}};
    
bool compare(char c1, char c2){
    return code[c1] < code[c2];
}

class Solution {
  public:
    void matchPairs(int n, char nuts[], char bolts[]) {
        sort(nuts, nuts + n, compare);
        
        for(int i = 0; i < n; i++)
            bolts[i] = nuts[i];
            
        return;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(n, nuts, bolts);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends