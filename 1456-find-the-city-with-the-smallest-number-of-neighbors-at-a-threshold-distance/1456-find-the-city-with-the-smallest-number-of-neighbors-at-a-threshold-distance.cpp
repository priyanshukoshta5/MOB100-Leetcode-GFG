class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int> (n, 1e5));
        for(int i=0; i<n; i++)
            dist[i][i] = 0;
        for(auto e: edges)
        {
            dist[e[0]][e[1]] = e[2];
            dist[e[1]][e[0]] = e[2];
        }

        // Floyd Warshall
        for(int k=0; k<n; k++)
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);

        int ansCity = -1, minNeigbours = n, cnt = 0;
        for(int city=0; city<n; city++)
        {
            cnt = 0;
            for(int neigbourCity=0; neigbourCity<n; neigbourCity++)
                if(dist[city][neigbourCity] <= distanceThreshold)
                    cnt++;

            if(cnt <= minNeigbours)
            {
                minNeigbours = cnt;
                ansCity = city;
            }
        }

        return ansCity;  
    }
};