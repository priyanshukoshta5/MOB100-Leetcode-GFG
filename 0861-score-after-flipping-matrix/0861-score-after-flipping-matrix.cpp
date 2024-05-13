// ~Editorial

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Set first column
        for (int i = 0; i < n; i++) 
        {
            if (grid[i][0] == 0) 
            {
                // Flip row
                for (int j = 0; j < m; j++)
                    grid[i][j] = 1 - grid[i][j];
            }
        }

        // Optimize columns except first column
        for (int j = 1; j < m; j++) 
        {
            int countZero = 0;
            // Count zeros
            for (int i = 0; i < n; i++) 
            {
                if (grid[i][j] == 0)
                    countZero++;
            }
            // Flip the column if there are more zeros for better score
            if (countZero > n - countZero) 
            {
                for (int i = 0; i < n; i++)
                    grid[i][j] = 1 - grid[i][j];
            }
        }

        int ans = 0;
        for(int r = 0; r < n; r++)
        {
            int power = 1;
            for(int c = m - 1; c >= 0; c--)
            {
                ans = ans + (grid[r][c] * power);
                power = power * 2;
            }
        }

        return ans;
    }
};