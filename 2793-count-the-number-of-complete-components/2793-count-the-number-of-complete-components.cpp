class Solution {
private:
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis, int &nodes, int &edges){
        // cout<<node<<endl;
        nodes++;
        vis[node] = true;
        for(int adjNode: adj[node]){
            edges++;
            if(!vis[adjNode]){
                dfs(adjNode, adj, vis, nodes, edges);
            }
        }
        return;
    }

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int cnt = 0;
        vector<bool> vis(n, false);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                int nodes = 0;
                int edges = 0;
                dfs(i, adj, vis, nodes, edges);
                // cout<<nodes<<" "<<edges<<endl;
                if(edges == (nodes * (nodes - 1)))
                    cnt++;
            }
        }

        return cnt;
    }
};