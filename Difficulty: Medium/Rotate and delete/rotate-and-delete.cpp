//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int rotateDelete(vector<int> &arr) {
        int n = arr.size();
        for(int k = 0; k < n/2; k++)
        {
            int val = arr[n - k - 1];
            for(int i = n - k - 1; i > 0; i--)
                arr[i] = arr[i - 1];
            arr[0] = val;
            // for(int z: arr)
            //     cout<<z<<" ";
            // cout<<" : ";
            arr.erase(arr.begin() + (arr.size() - k - 1));
            // for(int z: arr)
            //     cout<<z<<" ";
            // cout<<endl;
        }
        return arr[0];
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.rotateDelete(arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends