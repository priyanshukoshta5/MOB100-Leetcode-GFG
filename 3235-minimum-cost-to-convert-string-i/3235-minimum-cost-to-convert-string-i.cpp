class Solution {
private:
    long long INF = 1e8;
    void floydWarshall(vector<vector<long long>> &dist)
    {
        int V = dist.size();
        int i, j, k;
        for (k = 0; k < V; k++) 
        {
            for (i = 0; i < V; i++) 
            {
                for (j = 0; j < V; j++) 
                {
                    if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INF && dist[i][k] != INF))
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> dist(26, vector<long long> (26, INF));
        for(int i = 0; i < original.size(); i++)
        {
            int a = original[i] - 'a';
            int b = changed[i] - 'a';
            dist[a][b] = min(dist[a][b], 1LL * cost[i]);
        }
        
        floydWarshall(dist);
        
        // for(int i = 0; i < 26; i++)
        // {
        //     for(int j = 0; j < 26; j++)
        //     {
        //         if(dist[i][j] == INF)
        //             cout<<0<<" ";
        //         else 
        //             cout<<dist[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        long long minCost = 0;
        for(int i = 0; i < source.length(); i++)
        {
            int a = source[i] - 'a';
            int b = target[i] - 'a';
            if(a == b)
                continue;
            if(dist[a][b] == INF)
                return -1;
            minCost += dist[a][b];
        }
        
        return minCost;
    }
};