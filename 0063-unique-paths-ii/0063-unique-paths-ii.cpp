class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        // if start or end contains an obstacle
        if(obstacleGrid[0][0] == 1 || obstacleGrid[n - 1][m - 1] == 1)
            return 0;

        vector<vector<int>> dp(n, vector<int> (m, 0));
        dp[0][0] = 1;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                // up paths
                int up = 0;
                if((i - 1) >= 0 && obstacleGrid[i - 1][j] == 0)
                    up = dp[i - 1][j];

                // left paths
                int left = 0;
                if((j - 1) >= 0 && obstacleGrid[i][j - 1] == 0)
                    left = dp[i][j - 1];

                dp[i][j] = dp[i][j] + left + up;
            }
        }

        return dp[n - 1][m - 1];
    }
};