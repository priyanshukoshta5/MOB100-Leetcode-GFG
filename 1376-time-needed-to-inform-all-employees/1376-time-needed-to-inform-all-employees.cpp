class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++)
            if(i != headID)
                adj[manager[i]].push_back(i);
        
        int maxMins = 0;
        queue<pair<int,int>> q;     // {ID, time}
        q.push({headID, 0});
        while(!q.empty())
        {
            int id = q.front().first;
            int tm = q.front().second;
            q.pop();
            maxMins = max(maxMins, tm);
            for(int child: adj[id])
                q.push({child, tm + informTime[id]});
        }

        return maxMins;
    }
};