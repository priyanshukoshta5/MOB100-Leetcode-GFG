class Solution {
private:
    vector<int> topoSort(int N, vector<vector<int>> &adj) {
        queue<int> q; 
	    vector<int> indegree(N, 0); 
	    for(int i = 1; i < N; i++) {
	        for(auto it: adj[i]) {
	            indegree[it]++; 
	        }
	    }
	    
	    for(int i = 1; i < N; i++) {
	        if(indegree[i] == 0) {
	            q.push(i); 
	        }
	    }
	    vector<int> topo;
	    while(!q.empty()) {
	        int node = q.front(); 
	        q.pop(); 
	        topo.push_back(node);
	        for(auto it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it); 
	            }
	        }
	    }

        if(topo.size() != N-1)
            topo.clear();

	    return topo;
	}

public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> rowG(k + 1);
        vector<vector<int>> colG(k + 1);
        for(auto e: rowConditions)
            rowG[e[0]].push_back(e[1]);
        for(auto e: colConditions)
            colG[e[0]].push_back(e[1]);

        vector<int> rowTopo = topoSort(k + 1, rowG);
        vector<int> colTopo = topoSort(k + 1, colG);

        if(rowTopo.size() == 0 || colTopo.size() == 0)
            return {};

        // for(int i = 0; i < rowTopo.size(); i++)
        //     cout<<rowTopo[i]<<" "<<colTopo[i]<<endl;
        
        vector<int> rowI(k + 1);
        vector<int> colI(k + 1);
        for(int i = 1; i < rowTopo.size(); i++)
        {
            rowI[rowTopo[i]] = i;
            colI[colTopo[i]] = i;
        }

        vector<vector<int>> ans(k, vector<int> (k, 0));
        for(int i = 1; i <= k; i++)
            ans[rowI[i]][colI[i]] = i;

        return ans;;
    }
};