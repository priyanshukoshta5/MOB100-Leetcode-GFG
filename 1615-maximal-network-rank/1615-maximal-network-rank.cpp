class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        // creating adjancy list
        vector<vector<int>> adj(n);
        for(auto e: roads)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // taking all pairs of nodes, and finding answer
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                int res = adj[i].size() + adj[j].size();    
                // if there is a road between i and j
                if(find(adj[i].begin(), adj[i].end(), j) != adj[i].end())   
                    res--;
                ans = max(ans, res);
            }
        }

        return ans;
    }
};