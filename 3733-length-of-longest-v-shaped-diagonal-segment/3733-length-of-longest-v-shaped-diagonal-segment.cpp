class Solution {
private:
    int dp[500][500][15];
    int dir[4][2] = {{-1, +1}, {+1, +1}, {+1, -1}, {-1, -1}};

    bool isValid(int i, int j, int rows, int cols){
        return i >= 0 && i < rows && j >= 0 && j < cols;
    }

    int solve(int i, int j, int k, vector<vector<int>> &grid, bool isTurned, int rows, int cols){
        // cout<<i<<" "<<j<<" "<<k<<" "<<isTurned<<endl;
        
        if(dp[i][j][k + (isTurned * 10)] != -1)
            return dp[i][j][k + (isTurned * 10)];
        
        int next = -1;
        if(grid[i][j] == 0) next = 2;
        else next = 0;

        int res = 0, ans = 0;

        if(isValid(i + dir[k][0], j + dir[k][1], rows, cols) && grid[i + dir[k][0]][j + dir[k][1]] == next){
            res = solve(i + dir[k][0], j + dir[k][1], k, grid, isTurned, rows, cols);
            ans = max(ans, res);
        }   // if in same direction

        if(isTurned == true)
            return dp[i][j][k + (isTurned * 10)] = 1 + ans;

        int nK = (k + 1) % 4;
        if(isValid(i + dir[nK][0], j + dir[nK][1], rows, cols) && grid[i + dir[nK][0]][j + dir[nK][1]] == next){
            res = solve(i + dir[nK][0], j + dir[nK][1], nK, grid, true, rows, cols);
            ans = max(ans, res);
        }   // if right 90degree turn

        return dp[i][j][k + (isTurned * 10)] = 1 + ans;
    }

public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));

        int rows = grid.size();
        int cols = grid[0].size();
        
        int ans = 0, res = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] != 1)
                    continue;

                ans = max(ans, 1);      // atleast there is 1 cell
                for(int k = 0; k < 4; k++){
                    if(isValid(i + dir[k][0], j + dir[k][1], rows, cols) && grid[i + dir[k][0]][j + dir[k][1]] == 2){
                        res = solve(i + dir[k][0], j + dir[k][1], k, grid, false, rows, cols);
                        ans = max(ans, 1 + res);
                    }
                }
            }

            // cout<<ans<<endl;
        }

        return ans;
    }
};