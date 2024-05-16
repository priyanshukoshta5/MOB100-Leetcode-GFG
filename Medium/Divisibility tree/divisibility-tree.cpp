//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
private:
    int dfs(int node, int parent, vector<vector<int>> &adj, int &ans){
        int temp = 0;
        for(int i: adj[node])
        {
            if(i == parent)
                continue;
            
            int size = dfs(i, node, adj, ans);
            if(size % 2 == 0)
                ans++;
            
            temp += (size % 2);
        }
        
        return 1 + temp % 2;
    }
    
public:
	int minimumEdgeRemove(int n, vector<vector<int>>edges){
	    if(n % 2 == 1)
	        return -1;
	        
	    vector<vector<int>> adj(n + 1);
	    for(auto e: edges)
	    {
	        adj[e[0]].push_back(e[1]);
	        adj[e[1]].push_back(e[0]);
	    }
	    
	    int ans = 0;
	    dfs(1, -1, adj, ans);
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>edges;
		for(int i = 0; i < n-1; i++){
			int x, y;
			cin >> x >> y;
			edges.push_back({x,y});
		}
		Solution obj;
		int ans = obj.minimumEdgeRemove(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}

// } Driver Code Ends