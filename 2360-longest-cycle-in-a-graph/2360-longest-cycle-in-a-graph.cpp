class Solution {
private:
    void dfs(int node, vector<int>& edges, vector<int>& parent, vector<int>& dist, vector<int>& visited, vector<int>& pass, int& maxCycle){
        // cout<<node<<endl;

        int cur_dist = dist[node];
        int cur_pass = pass[node];
        int adjNode = edges[node];
        
        // If there to no child node
        if(adjNode == -1)
            return;

        // If not visited, just continue and visit it.
        if(!visited[adjNode])
        {
            visited[adjNode] = 1;
            parent[adjNode] = node;
            dist[adjNode] = cur_dist+1;
            pass[adjNode] = cur_pass;
            dfs(adjNode, edges, parent, dist, visited, pass, maxCycle);
        }
        // If visited in the same pass, means there is a Cycle, so find its length
        else if(cur_pass == pass[adjNode] && parent[adjNode] != node)
            maxCycle = max(maxCycle, (cur_dist+1)-dist[adjNode]);
    }

public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        // 'pass' to store the time we are applying DFS, to avoid multiple nodes visiting a node in different pass.
        vector<int> parent(n,-1), dist(n,0), visited(n,0), pass(n);

        int maxCycle = -1;
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                pass[i] = i;
                visited[i] = 1;
                dfs(i, edges, parent, dist, visited, pass, maxCycle);
            }
        }

        return maxCycle; // if no cycle returning -1
    }
};