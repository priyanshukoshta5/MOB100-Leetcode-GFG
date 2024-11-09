//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string minSum(vector<int> &arr) {
        sort(arr.begin(), arr.end(), greater<int> ());
        string ans = "";
        int rem = 0;
        for(int i = 0; i < arr.size(); i += 2)
        {
            int temp = arr[i];
            if((i + 1) < arr.size())
                temp += arr[i + 1];
            temp += rem;
            rem = temp / 10;
            ans.push_back('0' + (temp % 10));
        }
        if(rem > 0)
            ans.push_back('0' + rem);
        while(ans.length() > 1 && ans.back() == '0')
            ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends