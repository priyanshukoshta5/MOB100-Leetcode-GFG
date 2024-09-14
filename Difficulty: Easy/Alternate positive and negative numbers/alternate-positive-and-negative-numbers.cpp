//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        vector<int> pos, neg;
        for(int i: arr)
        {
            if(i >= 0)
                pos.push_back(i);
            else
                neg.push_back(i);
        }
        int i = 0, j = 0, k = 0;
        while(i < pos.size() && j < neg.size())
        {
            if(k % 2 == 0)
            {
                arr[k] = pos[i];
                k++;
                i++;
            }
            else
            {
                arr[k] = neg[j];
                k++;
                j++;
            }
        }
        
        while(i < pos.size())
        {
            arr[k] = pos[i];
            i++;
            k++;
        }
        
        while(j < neg.size())
        {
            arr[k] = neg[j];
            j++;
            k++;
        }
        
        return;
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
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends