//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    bool valid(int i, int j, int n, int m)
    {
        return i>=0 && i<n && j>=0 && j<m;
    }
    
  public:
    int shortestXYDist(vector<vector<char>> grid, int N, int M) {
        int ans = N+M;
        
        queue<pair<int, pair<int,int>>> q;   // {dist, i, j}
        vector<vector<int>> vis(N, vector<int> (M,0));
        
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                if(grid[i][j] == 'X')
                {
                    q.push({0, {i,j}});
                    vis[i][j] = 1;
                }
            }
        }
        
        int dr[] = {0,-1,0,1};
        int dc[] = {1,0,-1,0};
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int dist = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            for(int i=0; i<4; i++)
            {
                int newr = r+dr[i];
                int newc = c+dc[i];
                if(valid(newr, newc, N, M) && vis[newr][newc]==0)
                {
                    if(grid[newr][newc] == 'Y')
                    {
                        ans = min(ans, dist+1);
                        break;
                    }
                    vis[newr][newc] = 1;
                    q.push({dist+1, {newr, newc}});
                }
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
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends