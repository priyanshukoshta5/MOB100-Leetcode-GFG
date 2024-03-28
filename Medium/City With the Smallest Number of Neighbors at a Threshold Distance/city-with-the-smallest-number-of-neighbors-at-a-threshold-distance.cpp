//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int> (n, 1e7));
        for(auto e: edges)
        {
            int u = e[0];
            int v = e[1];
            int d = e[2];
            dist[u][v] = min(dist[u][v], d);
            dist[v][u] = min(dist[v][u], d);
        }
        for(int i = 0; i < n; i++)
            dist[i][i] = 0;
        
        // floyd warshall
        for(int k = 0; k < n; k++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        
        int minNeighbors = n;
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            int cnt = 0;
            for(int j = 0; j < n; j++)
            {
                if(i == j)
                    continue;
                if(dist[i][j] <= distanceThreshold)
                    cnt++;
            }
            if(cnt < minNeighbors)
            {
                res = i;
                minNeighbors = cnt;
            }
            else if(cnt == minNeighbors)
                res = i;
        }
        
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends