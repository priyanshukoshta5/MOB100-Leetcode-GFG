// ~ https://www.youtube.com/watch?v=DA7MNlDY4gk

class Solution {
private:
    vector<int> ans, count;

    void dfs1(int node, int parent, vector<vector<int>> &adj){
        // cout<<node<<" "<<parent<<endl;
        for(int child: adj[node])
        {
            if(child != parent)
            {
                dfs1(child, node, adj);
                count[node] += count[child];
                ans[node] += ans[child] + count[child]; 
            }
        }
        // count[node] += 1;
    }

    void dfs2(int node, int parent, vector<vector<int>> &adj){
        for(int child: adj[node])
        {
            if(child != parent)
            {
                ans[child] = ans[node] - count[child] + (count.size() - count[child]);
                dfs2(child, node, adj);
            }
        }
    }

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        count.resize(n, 1);
        ans.resize(n, 0);
        vector<vector<int>> adj(n);

        for(auto e: edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs1(0, -1, adj);    // to fill 'count' and find 'ans' for root '0'
        dfs2(0, -1, adj);    // to calculate answer for remaining nodes

        return ans;
    }
};