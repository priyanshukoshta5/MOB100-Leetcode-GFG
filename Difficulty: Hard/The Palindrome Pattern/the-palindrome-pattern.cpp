//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    bool isPalindromeRow(vector<int> &row){
        int i = 0, j = row.size() - 1;
        while(i < j)
        {
            if(row[i] != row[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    bool isPalindromeCol(vector<vector<int>> &arr, int c){
        int i = 0, j = arr.size() - 1;
        while(i < j)
        {
            if(arr[i][c] != arr[j][c])
                return false;
            i++;
            j--;
        }
        return true;
    }
    
  public:

    string pattern(vector<vector<int>> &arr) {
        vector<int> rowP, colP;
        for(int r = 0; r < arr.size(); r++)
        {
            if(isPalindromeRow(arr[r]))
                rowP.push_back(r);
        }
        
        for(int c = 0; c < arr[0].size(); c++)
        {
            if(isPalindromeCol(arr, c))
                colP.push_back(c);
        }
        
        // for(int i: rowP) cout<<i<<" "; cout<<endl;
        // for(int i: colP) cout<<i<<" "; cout<<endl;
        
        if(rowP.size() == 0 && colP.size() == 0)
            return "-1";
        else if(rowP.size() == 0)
            return to_string(colP[0]) + " C";
        else
            return to_string(rowP[0]) + " R";
    }
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends