class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if((m * n) == original.size())
        {
            vector<vector<int>> grid(m, vector<int> (n));
            int ptr = 0;
            for(int i = 0; i < m; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    grid[i][j] = original[ptr];
                    ptr++;
                }
            }
            return grid;
        }
        return {};
    }
};