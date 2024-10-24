//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        // Complete the function
        vector<int> myArray = arr;
        
        int n = myArray.size();
        for(int i = 0; i < n - 1; i++)
        {
            if(myArray[i] > 0 && myArray[i + 1] > 0 && myArray[i] == myArray[i + 1])
            {
                myArray[i] = myArray[i] * 2;
                myArray[i + 1] = 0;
            }
        }
        
        int i = 0, j = 0;
        while(j < n)
        {
            while(j < n && myArray[j] == 0)
                j++;
            while(i < j && myArray[i] != 0)
                i++;
            if(j < n)
                swap(myArray[i], myArray[j]);
            j++;
        }
        
        return myArray;
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
        vector<int> ans = obj.modifyAndRearrangeArray(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends