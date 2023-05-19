class Solution {
private:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& color, int col){
        for(int adj: graph[node])
        {
            if(color[adj] == -1)
            {
                color[adj] = !col;
                if(dfs(adj, graph, color, color[adj]) == false)
                    return false;
            }
            else if(color[adj] == col)
                return false;
        }
            
        return true;
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> color(n, -1);
        
        for(int i=0; i<n; i++)
        {
            if(color[i] == -1)
            {
                color[i] = 0;
                if(dfs(i, graph, color, 0) == false)
                    return false;
            }
        }
        
        return true;
    }
};