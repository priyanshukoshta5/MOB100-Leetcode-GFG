class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> adj(n);        // u = {v, wt}
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            double wt = succProb[i];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<double> dist(n, 0);
        priority_queue<pair<int, double>, vector<pair<int, double>>, greater<pair<int, double>>> q; // {node, prob_till_now}
        q.push({start, 1});
        while(!q.empty())
        {
            auto it = q.top();
            q.pop();
            int node = it.first;
            double prob = it.second;

            for(auto i: adj[node])
            {
                int adjNode = i.first;
                double adjProb = i.second;
                if(dist[adjNode] < (prob * adjProb))
                {
                    dist[adjNode] = prob * adjProb;
                    q.push({adjNode, dist[adjNode]});
                }
            }
        }

        return dist[end];
    }
};