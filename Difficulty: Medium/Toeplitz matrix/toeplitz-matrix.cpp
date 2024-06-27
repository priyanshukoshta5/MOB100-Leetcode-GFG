//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

bool isToeplitz(vector<vector<int>> &mat);

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        }

        bool b = isToeplitz(a);

        if (b == true)
            cout << "true";
        else
            cout << "false";

        cout << endl;
    }
    return 0;
}
// } Driver Code Ends



bool isToeplitz(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    
    for(int r = 0; r < n; r++)
    {
        int i = r, j = 0;
        int val = mat[i][j];
        while(i < n && j < m)
        {
            if(mat[i][j] != val)
                return false;
            i++;
            j++;
        }
    }
    
    for(int c = 1; c < m; c++)
    {
        int i = 0, j = c;
        int val = mat[i][j];
        while(i < n && j < m)
        {
            if(mat[i][j] != val)
                return false;
            i++;
            j++;
        }
    }
    
    return true;
}