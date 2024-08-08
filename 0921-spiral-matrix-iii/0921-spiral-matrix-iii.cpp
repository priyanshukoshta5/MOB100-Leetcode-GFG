class Solution {
public:
    bool isValid(int r, int c, int rows, int cols){
        return r >= 0 && r < rows && c >= 0 && c < cols;
    }

    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int left = 0, right = 0, up = 0, down = 0;
        int cnt = 0;
        vector<vector<int>> path;
        int i = rStart, j = cStart;
        int step = 1;
        while(cnt < (rows * cols))
        {
            // left to right
            for(int t = 0; t < step && cnt < (rows * cols); t++)
            {
                if(isValid(i, j, rows, cols))
                {
                    cnt++;
                    path.push_back({i, j});
                }
                j++;
            }

            // up to down
            for(int t = 0; t < step && cnt < (rows * cols); t++)
            {
                if(isValid(i, j, rows, cols))
                {
                    cnt++;
                    path.push_back({i, j});
                }
                i++;
            }

            step++;

            // right to left
            for(int t = 0; t < step && cnt < (rows * cols); t++)
            {
                if(isValid(i, j, rows, cols))
                {
                    cnt++;
                    path.push_back({i, j});
                }
                j--;
            }

            // down to up
            for(int t = 0; t < step && cnt < (rows * cols); t++)
            {
                if(isValid(i, j, rows, cols))
                {
                    cnt++;
                    path.push_back({i, j});
                }
                i--;
            }

            step++;
        }

        return path;
    }
};