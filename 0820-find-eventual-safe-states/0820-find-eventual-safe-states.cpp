class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();   // number of nodes in the graph

        vector<int> adjRev[n];  // to store the edges in reverse order
        vector<int> inDeg(n, 0);    // for counting indegree of notes in reverse graph
        for(int i = 0; i < n; i++)
        {
            for(int adjNode: graph[i])
            {
                adjRev[adjNode].push_back(i);   // adding egde in reverse
                inDeg[i]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < n; i++)
            if(inDeg[i] == 0)       // pushing the which have no incoming edges in reverse graph
                q.push(i);

        vector<int> safeStates;     // to store answer states
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            safeStates.push_back(node);
            for(int adjNode: adjRev[node])
            {
                inDeg[adjNode]--;
                if(inDeg[adjNode] == 0)     // add adjNode only if the node is not the part of a cycle
                    q.push(adjNode);
            }
        }

        sort(safeStates.begin(), safeStates.end());

        return safeStates;
    }
};