//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int swapNibbles(int n) {
        vector<int> temp;
        for(int i = 0; i < 8; i++)
        {
            temp.push_back(n % 2);
            n = n / 2;
        }
        
        for(int i = 0; i < 4; i++)
            swap(temp[i], temp[i + 4]);
            
        int ans = 0;
        for(int i = 0; i < 8; i++)
            ans = ans + pow(2, i) * temp[i];
        
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
        Solution ob;
        cout << ob.swapNibbles(n) << endl;
    }
    return 0;
}
// } Driver Code Ends