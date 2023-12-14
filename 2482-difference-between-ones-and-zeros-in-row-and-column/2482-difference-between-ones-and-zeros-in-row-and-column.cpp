class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> rowVal(n, 0);
        vector<int> colVal(m, 0);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                {
                    rowVal[i]++;
                    colVal[j]++;
                }
                else
                {
                    rowVal[i]--;
                    colVal[j]--;
                }
            }
        }

        vector<vector<int>> diffMat(n, vector<int> (m));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                diffMat[i][j] = rowVal[i] + colVal[j];

        return diffMat;
    }
};