//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

unordered_map<int, int> freqMap;

class Solution {
  public:
    static bool compare(int a, int b){
        if(freqMap[a] == freqMap[b])
            return a < b;
        return freqMap[a] > freqMap[b];
    }
  
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        freqMap.clear();
        for(int i: arr)
            freqMap[i]++;
        sort(arr.begin(), arr.end(), compare);
        return arr;
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
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends