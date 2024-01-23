//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        vector<vector<int>> adj(n);
        vector<int> inDeg(n, 0);
        for(auto preq: prerequisites)
        {
            adj[preq[1]].push_back(preq[0]);
            inDeg[preq[0]]++;
        }
        
        vector<int> topo;
        queue<int> q;
        for(int i = 0; i < n; i++)
            if(inDeg[i] == 0)
                q.push(i);
        
        while(!q.empty())
        {
            int node = q.front();   q.pop();
            topo.push_back(node);
            for(int i: adj[node])
            {
                inDeg[i]--;
                if(inDeg[i] == 0)
                    q.push(i);
            }
        }
        
        if(topo.size() != n)
            topo.clear();
            
        return topo;
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends