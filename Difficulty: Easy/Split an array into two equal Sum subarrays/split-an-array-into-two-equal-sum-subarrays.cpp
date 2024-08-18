//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        int i = 0, j = arr.size() - 1;
        int sum = 0;
        while(i <= j)
        {
            if(sum <= 0)
            {
                sum += arr[i];
                i++;
            }
            else
            {
                sum -= arr[j];
                j--;
            }
        }
        // cout<<sum<<endl;
        return sum == 0;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t-- > 0) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }

        Solution obj;
        bool res = obj.canSplit(arr);
        cout << (res ? "true" : "false") << endl;
    }
    return 0;
}
// } Driver Code Ends