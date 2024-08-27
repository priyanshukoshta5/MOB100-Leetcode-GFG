//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        int n = arr.size();
        
        stack<int> stk;
        stk.push(0);
        vector<int> leftSmaller(n);
        for(int i = 0; i < n; i++)
        {
            while(stk.top() >= arr[i])
                stk.pop();
            leftSmaller[i] = stk.top();
            stk.push(arr[i]);
        }
        
        while(!stk.empty())
            stk.pop();
        stk.push(0);
        vector<int> rightSmaller(n);
        for(int i = n - 1; i >= 0; i--)
        {
            while(stk.top() >= arr[i])
                stk.pop();
            rightSmaller[i] = stk.top();
            stk.push(arr[i]);
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            ans = max(ans, abs(leftSmaller[i] - rightSmaller[i]));
            // cout<<arr[i]<<" "<<leftSmaller[i]<<" "<<rightSmaller[i]<<endl;
        }
            
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends