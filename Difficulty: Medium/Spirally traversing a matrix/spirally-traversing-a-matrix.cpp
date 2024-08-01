//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<int> ans;
        int up=0, down=r-1, left=0, right=c-1;
        int i=0, j=0;
        int cnt=r*c;
        while(up<=down && left<=right && cnt>0)
        {
            while(j<right && cnt>0)
            {
                ans.push_back(matrix[i][j]);
                j++;
                cnt--;
            }
            up++;
            
            while(i<down && cnt>0)
            {
                ans.push_back(matrix[i][j]);
                i++;
                cnt--;
            }
            right--;
            
            while(j>left && cnt>0)
            {
                ans.push_back(matrix[i][j]);
                j--;
                cnt--;
            }
            down--;
            
            while(i>up && cnt>0)
            {
                ans.push_back(matrix[i][j]);
                i--;
                cnt--;
            }
            left++;
        }
        if(cnt==1) ans.push_back(matrix[i][j]);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends