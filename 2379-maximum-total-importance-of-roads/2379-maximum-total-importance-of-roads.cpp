class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> adjEdges(n, 0);
        for(auto r: roads)
        {
            adjEdges[r[0]]++;
            adjEdges[r[1]]++;
        }

        priority_queue<int> maxH;
        for(int i = 0; i < n; i++)
            maxH.push(adjEdges[i]);

        long long ans = 0;
        long long imp = n;
        while(!maxH.empty())
        {
            ans += (imp * maxH.top());
            maxH.pop();
            imp--;
        }

        return ans;
    }
};