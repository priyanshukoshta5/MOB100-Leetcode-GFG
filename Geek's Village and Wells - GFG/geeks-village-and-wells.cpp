//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool isValid(int r, int c, int n, int m){
        return r>=0 && r<n && c>=0 && c<m;
    }

    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &c){
        vector<vector<int>> ans(n, vector<int> (m, -1));
        vector<vector<int>> visited(n, vector<int> (m, 0));
        
        queue<pair<pair<int,int>, pair<int,int>>> q; // {cur node, source node}
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(c[i][j] == 'W')
                {
                    q.push({{i,j},{i,j}});
                    ans[i][j] = 0;
                    visited[i][j] = 1;
                }
                else if(c[i][j] != 'H')
                    ans[i][j] = 0;
            }
        }
        
        int dr[] = {0,-1,0,+1};
        int dc[] = {-1,0,+1,0};
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            auto cur = it.first;
            auto well = it.second;
            
            if(c[cur.first][cur.second] == 'H')
            {
                int dist = 2 * (abs(well.first-cur.first) + abs(well.second-cur.second));
                ans[cur.first][cur.second] = dist;
            }
            
            for(int i=0; i<4; i++)
            {
                int row = cur.first + dr[i];
                int col = cur.second + dc[i];
                if(isValid(row, col, n, m) && c[row][col] != 'N' && visited[row][col] == 0)
                {
                    q.push({{row,col}, well});
                    visited[row][col] = 1;
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> c(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> res=ob.chefAndWells(n,m,c);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
// } Driver Code Ends