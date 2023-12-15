class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> adj;
        for(auto p: paths)
            adj[p[0]] = p[1];
        string temp = paths[0][0];
        while(adj.find(temp) != adj.end())
            temp = adj[temp];
        return temp;
    }
};