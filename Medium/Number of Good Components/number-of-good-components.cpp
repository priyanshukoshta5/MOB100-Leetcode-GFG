//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        vector<vector<int>> adj(v);
        for(auto e: edges)
        {
            adj[e[0] - 1].push_back(e[1] - 1);
            adj[e[1] - 1].push_back(e[0] - 1);
        }
        
        int ans = 0;
        vector<int> vis(v, 0);
        for(int i = 0; i < v; i++)
        {
            if(vis[i] == 0)
            {
                int edges = 0;
                int nodes = 0;
                queue<int> q;
                q.push(i);
                vis[i] = 1;
                while(!q.empty())
                {
                    int node = q.front(); q.pop();
                    edges += adj[node].size();
                    nodes++;
                    for(int adjNode: adj[node])
                    {
                        if(vis[adjNode] == 0)
                        {
                            vis[adjNode] = 1;
                            q.push(adjNode);
                        }
                    }
                }
                
                edges = edges / 2;
                if((nodes * (nodes - 1)) / 2 == edges)      // fully connected component
                    ans++;
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        int res = obj.findNumberOfGoodComponent(e, v, edges);

        cout << res << endl;
    }
}

// } Driver Code Ends