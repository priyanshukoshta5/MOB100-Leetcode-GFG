//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet{
    private:
    vector<int> parent, size;

    public:
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n);
        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
        
    int findUPar(int node){
        if(parent[node] == node)
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    
    void unionBySize(int u, int v){
        int uP = findUPar(u);
        int vP = findUPar(v);
        
        if(uP == vP)
            return;
        else if(size[uP] >= size[vP])
        {
            size[uP] += size[vP];
            parent[vP] = uP;
        }
        else
        {
            size[vP] += size[uP];
            parent[uP] = vP;
        }
    }
    
};

class Solution
{
    public:
    //Function to detect cycle using DSU in an undirected graph.
	int detectCycle(int V, vector<int>adj[])
	{
	    DisjointSet ds(V);
	    
	    set<pair<int, int>> st;
	    for(int i = 0; i < V; i++)
	    {
	        for(int j = 0; j < adj[i].size(); j++)
	        {
	            int u = i;
	            int v = adj[i][j];
	            if(ds.findUPar(u) == ds.findUPar(v) && st.find({u, v}) == st.end())
	                return 1;
	            
	            ds.unionBySize(u, v);
	            st.insert({u, v});
	            st.insert({v, u});
	        }
	    }
	    
	    return 0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends