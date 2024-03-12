//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
        int n = mat.size();
        
        vector<vector<int>> temp(2*n - 1);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                temp[i + j].push_back(mat[i][j]);
        }
        
        for(int i = 0; i < temp.size(); i += 2)
            reverse(temp[i].begin(), temp[i].end());
            
        vector<int> ans;
        for(int i = 0; i < temp.size(); i++)
        {
            for(int j = 0; j < temp[i].size(); j++)
                ans.push_back(temp[i][j]);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends