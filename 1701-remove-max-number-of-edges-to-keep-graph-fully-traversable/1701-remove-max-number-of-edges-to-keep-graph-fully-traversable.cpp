class DisjointSet{
    private:
        vector<int> parent, size;
        int components;
    
    public:
        DisjointSet(int n){
            components = n;
            parent.resize(n+1);
            size.resize(n+1);
            for(int i=0; i<=n; i++)
            {
                parent[i] = i;
                size[i] = 1;;
            }
        }

        int getUltimateParent(int node){
            if(parent[node] == node)
                return node;
            return parent[node] = getUltimateParent(parent[node]);
        }

        int unionBySize(int u, int v){
            int x = getUltimateParent(u);
            int y = getUltimateParent(v);

            if(x == y)
                return 0;

            if(size[x] > size[y]){
                parent[y] = x;
                size[x] += size[y];
            }
            else{
                parent[x] = y;
                size[y] += size[x];
            }

            components--;
            return 1;
        }

        bool isConnected(){
            return components == 1;
        }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet alice(n), bob(n);
        int edgesReq = 0;

        for(auto e: edges)
        {
            if(e[0] == 3)
                edgesReq += alice.unionBySize(e[1], e[2]) | bob.unionBySize(e[1], e[2]);
        }

        for(auto e: edges)
        {
            if(e[0] == 1)
                edgesReq += alice.unionBySize(e[1], e[2]);
            else if(e[0] == 2)
                edgesReq += bob.unionBySize(e[1], e[2]);
        }

        if(alice.isConnected() && bob.isConnected())
            return edges.size() - edgesReq;

        return -1;
    }
};