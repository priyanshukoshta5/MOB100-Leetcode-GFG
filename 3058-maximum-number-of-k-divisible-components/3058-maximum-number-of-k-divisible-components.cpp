class Solution {
private:
    int res = 0;
    
    long long int dfs(int node, vector<bool> &vis, vector<vector<int>> &adj, vector<int> &values, int k){       
        vis[node] = true;
        
        long long int total = values[node];
        
        for(int adjN: adj[node])
        {
            if(vis[adjN] == false)
            {
                long long int temp = dfs(adjN, vis, adj, values, k);
                if(temp % k == 0)
                    res++;
                total += temp;
            }
        }
        
        return total;
    }
    
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for(auto e: edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<bool> vis(n, false);
        long long int total = dfs(0, vis, adj, values, k);
        if(total % k != 0)
            return 0;
        
        return res + 1; 
    }
};