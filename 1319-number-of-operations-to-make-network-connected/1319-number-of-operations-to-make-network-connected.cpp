class DisjointSet{
private:
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

    int getUltimateParent(int node){
        if(parent[node] == node)
            return node;
        return parent[node] = getUltimateParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int up_u = getUltimateParent(u);
        int up_v = getUltimateParent(v);
        if(up_u == up_v)
            return;

        if(size[up_u] < size[up_v])
        {
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        }
        else
        {
            parent[up_v] = up_u;
            size[up_u] += size[up_v];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extra_wires = 0;
        for(auto conn: connections){
            if(ds.getUltimateParent(conn[0]) == ds.getUltimateParent(conn[1]))
                extra_wires++;
            else
                ds.unionBySize(conn[0], conn[1]);
        }

        int components = 0;
        for(int i=0; i<n; i++){
            // cout<<i<<" "<<ds.getUltimateParent(i)<<endl;
            if(ds.getUltimateParent(i) == i)
                components++;
        }

        int ans = components-1;        
        if(extra_wires >= ans)
            return ans;
        return -1;
    }
};