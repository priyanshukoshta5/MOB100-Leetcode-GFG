class Solution {
public:
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {-1, 0, 1, 0};

    int isValid(int r, int c, int n, int m){
        return r >= 0 && r < n && c >= 0 && c < m;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> efforts(n, vector<int> (m, INT_MAX));

        priority_queue<pair<int, pair<int,int>>, 
                        vector<pair<int, pair<int,int>>>, 
                        greater<pair<int, pair<int,int>>> > q;  // {max diff, {r, c}}

        // starting point
        q.push({0, {0,0}}); 
        efforts[0][0] = 0;

        while(!q.empty())
        {
            auto it = q.top();    q.pop();
            int diff = it.first;
            int r = it.second.first;
            int c = it.second.second;

            // if reached last point
            if(r == n - 1 && c == m - 1)
                return diff;

            // if already visited current node with less efforts
            if(diff > efforts[r][c])
                continue;

            // visiting 4 directions
            for(int i = 0; i < 4; i++)
            {
                int newR = r + dr[i];
                int newC = c + dc[i];
                if(isValid(newR, newC, n, m))
                {
                    int curDiff = max(diff, abs(heights[r][c] - heights[newR][newC]));
                    if(curDiff < efforts[newR][newC])
                    {
                        efforts[newR][newC] = curDiff;
                        q.push({curDiff, {newR, newC}});
                    }
                }
            }
        }

        return -1;
    }
};