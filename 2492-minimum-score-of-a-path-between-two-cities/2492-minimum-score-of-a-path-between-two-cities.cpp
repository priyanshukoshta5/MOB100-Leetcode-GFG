class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);  // {node, cost}
        for(auto it: roads)
        {
            int u = it[0];
            int v = it[1];
            int cost = it[2];
            adj[u].push_back({v,cost});
            adj[v].push_back({u,cost});
        }

        int ans = INT_MAX;
        vector<int> visited(n+1,0);
        queue<int> q;
        q.push(1);
        visited[1] = 1;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto it: adj[node])
            {
                int adjnode = it.first;
                int adjcost = it.second;
                if(!visited[adjnode])
                {
                    q.push(adjnode);
                    ans = min(ans, adjcost);
                    visited[node] = 1;
                }
            }
        }

        return ans;
    }
};