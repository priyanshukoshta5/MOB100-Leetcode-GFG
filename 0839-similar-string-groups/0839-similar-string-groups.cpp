class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited){
        visited[node] = 1;
        for(int neighbor: adj[node])
            if(!visited[neighbor])
                dfs(neighbor, adj, visited);
    }
    
    bool isSimilar(string& a, string& b){
        int cnt = 0;
        for(int i=0; i<a.length(); i++)
            if(a[i] != b[i])
                cnt++;
        return cnt == 0 || cnt == 2;
    }
    
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++)
        {
            for(int j = i+1; j<n; j++)
            {
                if(isSimilar(strs[i], strs[j]))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<int> visited(n);
        int groups = 0;
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                groups++;
                dfs(i, adj, visited);
            }
        }
        
        return groups;
    }
};