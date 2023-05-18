//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    private:
    bool isValid(int r, int c, int N, int M){
        return r >= 0 && r < N && c >= 0 && c < M;
    }
    
    void bfs(vector<vector<int>>& matrix, int i, int j, int N, int M, vector<vector<int>>& vis){
        queue<pair<int,int>> q;
        q.push({i, j});
        vis[i][j] = 1;
        
        int dr[] = {-1, 0, +1, 0};
        int dc[] = {0, +1, 0, -1};
        
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(int k = 0; k < 4; k++)
            {
                int newR = r + dr[k];
                int newC = c + dc[k];
                if(isValid(newR, newC, N, M) == true && matrix[newR][newC] == 1 && vis[newR][newC] == 0)
                {
                    vis[newR][newC] = 1;
                    q.push({newR, newC});
                }
            }
        }
    }
    
    public:
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        vector<vector<int>> vis(N, vector<int> (M, 0));
        
        // marking the islands on the boundary
        for(int i=0; i<N; i++)
        {
            if(matrix[i][0] == 1 && vis[i][0] == 0)         // Leftmost Col
                bfs(matrix, i, 0, N, M, vis);
                
            if(matrix[i][M-1] == 1 && vis[i][M-1] == 0)     // Rightmost Col
                bfs(matrix, i, M-1, N, M, vis);
        }
        for(int j=0; j<M; j++)
        {
            if(matrix[0][j] == 1 && vis[0][j] == 0)         // Topmost Row 
                bfs(matrix, 0, j, N, M, vis);
                
            if(matrix[N-1][j] == 1 && vis[N-1][j] == 0)     // Bottommost Row
                bfs(matrix, N-1, j, N, M, vis);
        }
        
        // Counting the islands
        int cnt = 0;
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                if(matrix[i][j] == 1 && vis[i][j] == 0)
                {
                    bfs(matrix, i, j, N, M, vis);
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends