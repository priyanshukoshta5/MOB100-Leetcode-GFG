class Solution {
private:
    // BFS TopoSort
    vector<int> topoSort(int n, vector<vector<int>> &adj){
        vector<int> inDegree(n, 0);
        for(int i = 0; i < n; i++)
            for(int j: adj[i])
                inDegree[j]++;
        
        vector<int> topo;
        queue<int> q;

        for(int i = 0; i < n; i++)
            if(inDegree[i] == 0)
                q.push(i);

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(int j: adj[node])
            {
                inDegree[j]--;
                if(inDegree[j] == 0)
                    q.push(j);
            }
        }

        return topo;
    }

    // BFS topoSort for elements within a group 
    vector<int> topoSort(vector<int> &arr, map<int, vector<int>> &adj){
        map<int, int> inDegree;
        for(int node: arr)
        {
            if(adj.find(node) != adj.end())
            {
                for(int j: adj[node])
                    inDegree[j]++;
            }
        }
        
        vector<int> topo;
        queue<int> q;

        for(int node: arr)
        {
            if(inDegree[node] == 0)
                q.push(node);
        }

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(int j: adj[node])
            {
                inDegree[j]--;
                if(inDegree[j] == 0)
                    q.push(j);
            }
        }

        return topo;
    }

public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        int extraGroup = m + 1;
        for(int i = 0; i < n; i++)
        {
            if(group[i] == -1)
            {
                group[i] = extraGroup;
                extraGroup++;
            }
        }

        vector<vector<int>> groupNodes(extraGroup);
        for(int i = 0; i < n; i++)
            groupNodes[group[i]].push_back(i);
        
        vector<vector<int>> adjGroup(extraGroup);
        vector<map<int, vector<int>>> adjWithinGroup(extraGroup);     // group[map]
        for(int i = 0; i < n; i++)
        {
            int grp1 = group[i];
            for(int j: beforeItems[i])
            {
                int grp2 = group[j];
                if(grp1 != grp2)
                    adjGroup[grp2].push_back(grp1);
                else
                    adjWithinGroup[grp1][j].push_back(i);
            }
        }

        vector<int> topoGroup = topoSort(extraGroup, adjGroup);
        
        // check for cycle in groups
        if(topoGroup.size() != (extraGroup))
            return {};

        vector<int> ans;

        for(int g: topoGroup)
        {
            int nElements = groupNodes[g].size();
            if(nElements == 0) 
                continue;

            vector<int> topoElements = topoSort(groupNodes[g], adjWithinGroup[g]);

            // cout<<"Group : "<<g<<", size : "<<nElements<<"  -  ";
            // for(int i: topoElements)
            //     cout<<i<<" ";
            // cout<<endl;

            // check for cycle within group
            if(topoElements.size() != nElements)
                return {};

            for(int i: topoElements)
                ans.push_back(i);
        }

        return ans;
    }
};