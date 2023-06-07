class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> indeg(n, 0);
        vector<vector<int>> adj(n);
        for(auto e: prerequisites)
        {
            adj[e[0]].push_back(e[1]);
            indeg[e[1]]++;
        }
        
        queue<int> q;
        for(int i=0; i<n; i++)
            if(indeg[i] == 0)
                q.push(i);
        
        int cnt = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            cnt++;
            
            for(auto it: adj[node])
            {
                indeg[it]--;
                if(indeg[it] == 0)
                    q.push(it);
            }
        }
        
        return cnt == n;
    }
};