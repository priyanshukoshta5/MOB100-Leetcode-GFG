class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, vector<pair<string, double>>> adj; // {u, {v, dist}}

        for(int i=0; i<equations.size(); i++)
        {
            // u -> v with weight 'value[i]'
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            // v -> u with weight '1/value[i]'
            adj[equations[i][1]].push_back({equations[i][0], 1/values[i]});
        } 

        vector<double> ans;
        for(auto q: queries)
        {
            if(adj.find(q[0]) == adj.end() || adj.find(q[1]) == adj.end())
            {
                ans.push_back(-1);
                continue;
            }

            double res = -1;
            map<string,bool> visited;
            queue<pair<string, double>> que;
            que.push({q[0], 1});
            visited[q[0]] = true;

            while(!que.empty())
            {
                auto it = que.front();
                string node = it.first;
                double wt = it.second;
                que.pop();
                // cout<<node<<" "<<wt<<endl;

                if(node == q[1])
                {
                    res = wt;
                    break;
                }

                for(auto adjNode: adj[node])
                {
                    string newNode = adjNode.first;
                    double newWt = wt*adjNode.second;
                    if(visited.find(newNode) == visited.end())
                    {
                        visited[newNode] = true;
                        que.push({newNode, newWt});
                    }
                }
            }

            // cout<<q[0]<<" "<<q[1]<<" "<<res<<endl;
            ans.push_back(res);
        }

        return ans;
    }
};