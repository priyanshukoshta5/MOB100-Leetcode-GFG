class DisJointSet{
private:
    vector<int> parent;
    vector<long long int> size;

public:
    DisJointSet(int n){
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
        long long int uPar = findUPar(u);
        long long int vPar = findUPar(v);
        if(uPar == vPar)
            return;
        else if(size[uPar] >= size[vPar])
        {
            size[uPar] += size[vPar];
            parent[vPar] = uPar;
        }
        else
        {
            size[vPar] += size[vPar];
            parent[uPar] = vPar;
        }
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 1)
            return 0;
        
        priority_queue< pair<long long int, pair<int,int>>, 
                        vector<pair<long long int, pair<int,int>>>, 
                        greater<pair<long long int, pair<int,int>>> > q;
        
        for(int i = 0; i < n - 1; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                long long int cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                if(cost <= INT_MAX)
                    q.push({cost, {i, j}});
            }
        }

        DisJointSet ds(n);
        long long int minCost = 0;
        while(!q.empty())
        {
            auto it = q.top();
            q.pop();
            long long int cost = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if(ds.findUPar(u) != ds.findUPar(v))
            {
                minCost += cost;
                ds.unionBySize(u, v);
            }
        }
        
        return minCost;
    }
};