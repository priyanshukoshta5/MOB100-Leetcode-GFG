//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<vector<pair<int,int>>> adj(N);
        for(auto e: edges)
            adj[e[0]].push_back({e[1], e[2]});
         
        vector<int> ans(N, INT_MAX);
        ans[0] = 0;
        
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int node = it.first;
            int dist = it.second;
            
            for(auto i: adj[node])
            {
                int adjNode = i.first;
                int adjDist = i.second;
                if(ans[adjNode] > (dist + adjDist))
                {
                    ans[adjNode] = dist + adjDist;
                    q.push({adjNode, ans[adjNode]});
                }
            }
        }
        
        for(int i = 0; i < N; i++)
            if(ans[i] == INT_MAX)
                ans[i] = -1;
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends