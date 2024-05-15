//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

// class DisjointSet{
//     private:
//         vector<int> parent, size;
//     public:
//         DisjointSet(int n){
//             parent.resize(n);
//             size.resize(n);
//             for(int i = 0; i < n; i++)
//             {
//                 parent[i] = i;
//                 size[i] = 1;
//             }
//         }
        
//         int getUPar(int node){
//             if(node == parent[node])
//                 return node;
//             return parent[node] = getUPar(parent[node]);
//         }
        
//         void unionBySize(int u, int v){
//             int uPar = getUPar(u);
//             int vPar = getUPar(v);
//             if(size[uPar] >= size[vPar])
//             {
//                 parent[vPar] = uPar;
//                 size[uPar] += size[vPar];
//             }
//             else
//             {
//                 parent[uPar] = vPar;
//                 size[vPar] += size[uPar];
//             }
//         }
// };

// class Solution {
//   public:
//     vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
//         int n = accounts.size();
        
//         DisjointSet ds(n);
//         unordered_map<string, int> mp;
//         for(int i = 0; i < n; i++)
//         {
//             for(int e = 1; e < accounts[i].size(); e++)
//             {
//                 string email = accounts[i][e];
//                 if(mp.find(email) == mp.end())
//                     mp[email] = i;
//                 else
//                     ds.unionBySize(mp[email], i);
//             }
//         }
        
//         // map<int, vector<int>> merged;
//         map<int, vector<string>> merged;
//         for(int i = 0; i < n; i++)
//         {
//             int par = ds.getUPar(i)
//             for(int e = 1; e < accounts[i].size(); e++)
//             {
//                 if(mp[accounts[i][e]] == i)
//                     merged[par].push_back()
//             }
//             // merged[ds.getUPar(i)].push_back(i);
//         }
        
//         vector<vector<string>> ans;
        
//         for(auto x: merged)
//         {
//             // cout<<x.first<<" -> ";
//             ans.push_back({accounts[x.first]});
//             for(int y: x.second)
//             {
//                 // cout<<y<<' ';
//                 for(int e = 1; e < accounts[y].size(); e++)
//                 {
//                     if(mp[accounts[y][e]] == y)
//                         ans.back().push_back(accounts[y][e]);
//                 }
//             }
//             // cout<<endl;
//         }
        
//         return ans;
//     }
// };

class DisjointSet{
    public:
	    vector<int> rank,parent;
	    DisjointSet(int n){
	        rank.resize(n+1,0);
	        parent.resize(n+1);
	        for(int i=0;i<=n;i++)parent[i]=i;
	    }
	    int findUpar(int node){
	        if(node==parent[node])return node;
	        return parent[node]=findUpar(parent[node]);
	    }
	    void Unionbyrank(int u,int v){
	        int u_v=findUpar(u);
	        int u_u=findUpar(v);
	        if(u_v==u_u)return;
	        if(rank[u_v]>rank[u_u])parent[u_u]=u_v;
	        else if(rank[u_v]<rank[u_u])parent[u_v]=u_u;
	        else{
	            parent[u_v]=u_u;
	            rank[u_u]++;
	        }
	    }
	};
class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        int  n=accounts.size();
        unordered_map<string,int> helper;
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(helper.find(mail)==helper.end())helper[mail]=i;
                else ds.Unionbyrank(i,helper[mail]);
                
            }
        }
        vector<vector<string>> ans;
        vector<string> merged[n];
        for(auto it:helper){
            string mail=it.first;
            int node=ds.findUpar(it.second);
            merged[node].push_back(mail);
        }
        for(int i=0;i<n;i++){
            if(merged[i].size()==0)continue;
            sort(merged[i].begin(),merged[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it:merged[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<string>> accounts;

        for (int i = 0; i < n; i++) {
            vector<string> temp;
            int x;
            cin >> x;

            for (int j = 0; j < x; j++) {
                string s1;
                cin >> s1;
                temp.push_back(s1);
            }
            accounts.push_back(temp);
        }

        ///
        Solution obj;
        vector<vector<string>> res = obj.accountsMerge(accounts);
        sort(res.begin(), res.end());
        cout << "[";
        for (int i = 0; i < res.size(); ++i) {
            cout << "[";
            for (int j = 0; j < res[i].size(); j++) {
                if (j != res[i].size() - 1)
                    cout << res[i][j] << ","
                         << " ";
                else
                    cout << res[i][j];
            }
            if (i != res.size() - 1)
                cout << "], " << endl;
            else
                cout << "]";
        }
        cout << "]" << endl;
    }
}
// } Driver Code Ends