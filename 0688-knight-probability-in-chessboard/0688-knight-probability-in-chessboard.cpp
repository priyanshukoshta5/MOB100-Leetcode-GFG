class Solution {
private:
    // 8 possibile moves of the Knight
    double dp[25][25][101];
    int dr[8] = {-2, -1, +1, +2, +2, +1, -1, -2};
    int dc[8] = {+1, +2, +2, +1, -1, -2, -2, -1};

    bool isValid(int r, int c, int n){
        return r >= 0 && r < n && c >= 0 && c < n;
    }

    double getProb(int n, int k, int row, int col){
        if(k == 0)
            return 1;

        if(dp[row][col][k] != -1)
            return dp[row][col][k];

        int inBoard = 0;

        double total = 0;
        for(int i = 0; i < 8; i++)
        {
            int newRow = row + dr[i];
            int newCol = col + dc[i];
            if(isValid(newRow, newCol, n))
            {
                inBoard++;
                total += getProb(n, k-1, newRow, newCol);
            }
        }

        if(inBoard == 0)
            return dp[row][col][k] = 0;
        return dp[row][col][k] = (double(inBoard) / double(8)) * (total / double(inBoard)) ; 
    }

public:
    double knightProbability(int n, int k, int row, int col) {
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int z = 0; z <= k; z++){
                    dp[i][j][z] = -1;
                }
            }
        }
        return getProb(n, k, row, col);
    }
};