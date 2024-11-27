class Solution {
private:
    int getMinDist(int source, int destination, vector<vector<int>> &adj){
        int jumps = 0;
        vector<bool> vis(adj.size(), false);
        queue<int> q;
        q.push(source);
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int node = q.front(); q.pop();
                vis[node] = true;
                if(node == destination)
                    return jumps;
                for(int adjNode: adj[node])
                {
                    if(vis[adjNode] == false)
                        q.push(adjNode);
                }    
            }
            jumps++;
        }
        return jumps;
    }

public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < n - 1; i++)
            adj[i].push_back(i + 1);

        vector<int> ans;
        for(auto q: queries)
        {
            adj[q[0]].push_back(q[1]);
            ans.push_back(getMinDist(0, n - 1, adj));
        }
        return ans;
    }
};