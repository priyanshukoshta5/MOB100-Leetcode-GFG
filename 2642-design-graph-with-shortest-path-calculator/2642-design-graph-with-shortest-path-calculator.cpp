class Graph {
private:
    vector<vector<pair<int,int>>> adj;
    int nodes;

public:
    Graph(int n, vector<vector<int>>& edges) {
        nodes = n;
        adj.resize(n);
        for(auto e: edges)
            adj[e[0]].push_back({e[1], e[2]});
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minH;
        vector<int> dist(nodes, INT_MAX);
        dist[node1] = 0;
        minH.push({0, node1});
        while(!minH.empty())
        {
            auto it = minH.top();
            minH.pop();
            int d = it.first;
            int node = it.second;
            if(node == node2)
                break;
            for(auto a: adj[node])
            {
                if((d + a.second) < dist[a.first])
                {
                    dist[a.first] = d + a.second;
                    minH.push({d + a.second, a.first});
                }
            }
        }
        if(dist[node2] == INT_MAX)
            return -1;
        return dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */