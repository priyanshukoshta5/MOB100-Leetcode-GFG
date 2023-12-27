//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
        int n = matrix.size();
        
        vector<int> ans;
        
        // left to right top row
        for(int t = 0; t < n; t++)
        {
            int i = 0, j = t;
            while(j >= 0)
            {
                ans.push_back(matrix[i][j]);
                i++;
                j--;
            }
        }
        
        // top to bottom rightmost column
        for(int t = 1; t < n; t++)
        {
            int i = t, j = n - 1;
            while(i < n)
            {
                ans.push_back(matrix[i][j]);
                i++;
                j--;
            }
        }
        
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
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends