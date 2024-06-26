//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  private:
    bool isValid(int r, int c, int n, int m){
        return r >= 0 && r < n && c >= 0 && c < m;
    }
    
  public:
    int findCoverage(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int cnt = 0;
        int dr[4] = {0, -1, 0, +1};
        int dc[4] = {-1, 0, +1, 0};
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] == 0)
                {
                    for(int k = 0; k < 4; k++)
                    {
                        if(isValid(i + dr[k], j + dc[k], n, m) && matrix[i + dr[k]][j + dc[k]] == 1)
                            cnt++;
                    }
                }
            }
        }
        return cnt;
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
        int ans = obj.findCoverage(matrix);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends