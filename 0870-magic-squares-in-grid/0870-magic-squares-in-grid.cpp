class Solution {
private:
    bool isMagicSquare(vector<vector<int>> &grid, int i, int j){
        set<int> st;
        for(int a = i; a < i + 3; a++)
        {
            for(int b = j; b < j + 3; b++)
            {
                if(grid[a][b] <= 0 || grid[a][b] > 9)
                    return false;
                st.insert(grid[a][b]);
            }
        }
        if(st.size() != 9)
            return false;
        
        int sum = grid[i][j] + grid[i][j + 1] + grid[i][j + 2]; // row1
        if(sum != (grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2])) // row2
            return false;
        if(sum != (grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2])) // row3
            return false;
        if(sum != (grid[i][j] + grid[i + 1][j] + grid[i + 2][j])) // col1
            return false;
        if(sum != (grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1])) // col2
            return false;
        if(sum != (grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2])) // col3
            return false;
        if(sum != (grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2])) // dia1
            return false;
        if(sum != (grid[i + 2][j] + grid[i + 1][j + 1] + grid[i][j + 2])) // dia2
            return false;

        return true;
    }

public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        for(int i = 0; i < n - 2; i++)
        {
            for(int j = 0; j < m - 2; j++)
            {
                if(grid[i][j] > 0 && grid[i][j] <= 9 && isMagicSquare(grid, i, j))
                    cnt++;
            }
        }
        return cnt;
    }
};