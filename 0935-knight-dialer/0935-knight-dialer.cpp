class Solution {
private:
    int MOD = 1e9+7;

    long long int dp[4][3][5000];

    vector<vector<int>> keyPad = {{1, 2, 3},
                                  {4, 5, 6},
                                  {7, 8 ,0},
                                  {-1, 0, -1}};

    vector<int> dr = {-2, -2, -1, +1, +2, +2, +1, -1};    // row movement
    vector<int> dc = {-1, +1, +2, +2, +1, -1, -2, -2};    // col movement

    bool isValid(int r, int c){
        return r >= 0 && r < 4 && c >= 0 && c < 3 && keyPad[r][c] != -1;
    }

    long long int getNumbers(int r, int c, int n){
        if(n == 0)
            return 1;
        
        if(dp[r][c][n] != -1)
            return dp[r][c][n];
        
        long long int res = 0;
        for(int i = 0; i < 8; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(isValid(nr, nc))
            {
                res += getNumbers(nr, nc, n - 1);
                res %= MOD;
            }
        }

        return dp[r][c][n] = res;
    }

public:
    int knightDialer(int n) {
        memset(dp, -1, sizeof(dp));

        long long int ans = 0;

        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(keyPad[i][j] == -1)
                    continue;
                ans = ans + getNumbers(i, j, n - 1);
                ans = ans % MOD;
            }
        }

        return ans;
    }
};