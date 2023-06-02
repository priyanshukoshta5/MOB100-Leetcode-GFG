class Solution {
public:
    double getDistance(vector<int>& a, vector<int>& b){
        double x = abs(a[0] - b[0]);
        double y = abs(a[1] - b[1]);
        return sqrt(pow(x, 2) + pow(y, 2));
    }

    int bfs(int node, vector<vector<int>>& adj){
        vector<int> vis(adj.size(), 0);
        queue<int> q;
        q.push(node);
        vis[node] = 1;
        int cnt = 0;
        while(!q.empty())
        {
            int i = q.front();
            q.pop();
            for(int j : adj[i])
            {
                if(vis[j] == 0)
                {
                    vis[j] = 1;
                    q.push(j);
                }
            }
            cnt++;
        }
        return cnt;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        // Making Directed Graph;
        int n = bombs.size();
        vector<vector<int>> adj(n);

        for(int i=0; i<n; i++)  // Selecting first bomb
        {
            for(int j=0; j<n; j++)  // Selection second bomb
            {
                double dist = getDistance(bombs[i], bombs[j]);

                // if r1 >= distance between centres, means i can detonate j
                if(i != j && bombs[i][2] >= dist)
                    adj[i].push_back(j);
            }
        }

        // for(int i=0; i<n; i++)
        // {
        //     cout<<i<<" : ";
        //     for(int j: adj[i])
        //         cout<<j<<" ";
        //     cout<<endl;
        // }

        int maxDetonation = 1;
        for(int i=0; i<n; i++)
            maxDetonation = max(maxDetonation, bfs(i, adj));

        return maxDetonation;
    }
};