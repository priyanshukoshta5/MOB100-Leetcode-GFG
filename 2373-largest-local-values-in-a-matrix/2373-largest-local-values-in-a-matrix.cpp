class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();   

        vector<vector<int>> ans(n - 2, vector<int> (n - 2, 0));
        for(int i = 0; i < n - 2; i++)
        {
            for(int j = 0; j < n - 2; j++)
            {
                for(int x = 0; x < 3; x++)
                    for(int y = 0; y < 3; y++)
                        ans[i][j] = max(ans[i][j], grid[i + x][j + y]);
            }
        }

        return ans;
    }
};