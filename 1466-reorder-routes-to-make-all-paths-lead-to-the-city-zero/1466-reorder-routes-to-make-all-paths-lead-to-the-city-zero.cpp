class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);   // parent -> {child, parent}
        for(auto conn: connections)
        {
            int u = conn[0];
            int v = conn[1];
            adj[u].push_back({v, 1});   // Edge in original direction
            adj[v].push_back({u, 0});   // Edge in reversed direction
        }

        int cnt = 0;
        vector<int> visited(n,0);
        queue<int> q;
        visited[0] = 1;
        q.push(0);
        while(!q.empty())
        {
            int city = q.front();
            q.pop();
            for(auto it: adj[city])
            {
                int adjCity = it.first;
                int direction = it.second;
                if(!visited[adjCity])
                {
                    visited[adjCity] = 1;
                    q.push(adjCity);
                    cnt += direction;
                }
            }
        }

        return cnt;
    }
};