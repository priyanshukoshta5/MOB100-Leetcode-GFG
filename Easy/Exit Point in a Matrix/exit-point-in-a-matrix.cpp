//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        int dir[4][2] = {{0, 1},    // right(initial)
                         {1, 0},    // down
                         {0, -1},   // left
                         {-1, 0}};  // up
        int curDir = 0;
        int i = 0, j = 0;
        vector<int> ans = {0, 0};
        while(i >= 0 && i < n && j >= 0 && j < m)
        {
            ans = {i, j};
            if(matrix[i][j] == 1)
            {
                curDir = (curDir + 1) % 4;
                matrix[i][j] = 0;
            }
            i += dir[curDir][0];
            j += dir[curDir][1];
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends