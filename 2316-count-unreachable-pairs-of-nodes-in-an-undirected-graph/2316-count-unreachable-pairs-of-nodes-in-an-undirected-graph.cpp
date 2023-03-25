class DisjointSet {
public:
    vector<int> parent, size;
public:
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int findUPar(int node){
        if(node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    
    void unionBySize(int u, int v){
        int upar_u = findUPar(u);
        int upar_v = findUPar(v);
        if(upar_u == upar_v)    // If already in a same cluster/group
            return;
        if(size[upar_u] >= size[upar_v]){
            parent[upar_v] = upar_u;
            size[upar_u] += size[upar_v];
        }
        else{
            parent[upar_u] = upar_v;
            size[upar_v] += size[upar_u];
        }
    }
};

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        for(auto e: edges){
            ds.unionBySize(e[0], e[1]);
        }
        
        long long ans = 0;
        for(int i=0; i<n; i++){
            ans = ans + (n-ds.size[ds.findUPar(i)]);
        }
        
        return ans/2;
    }
};