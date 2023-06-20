class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> prev(m), cur(m);
        
        // Base Case
        prev[0] = grid[0][0];
        for(int j = 1; j < m; j++)  prev[j] = prev[j-1] + grid[0][j];
        
        int pre = grid[0][0];
        for(int i = 1; i < n; i++)
        {
            pre += grid[i][0];
            cur[0] = pre;
            for(int j = 1; j < m; j++)
            {
                cur[j] = grid[i][j] + min(prev[j], cur[j-1]);
            }
            prev = cur;
        }
        
        return prev[m-1];
    }
};