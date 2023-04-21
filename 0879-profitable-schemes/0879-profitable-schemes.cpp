class Solution {
    int MOD = 1000000007;
    int dp[101][101][101];

private:
    int solve(int i, int prof, int size, int n, int minProfit, vector<int>& group, vector<int>& profit){
        if(i == profit.size())
            return prof >= minProfit;

        if(dp[i][prof][size] != -1)
            return dp[i][prof][size];

        int cnt = 0;

        // Not selecting ith group
        cnt += solve(i+1, prof, size, n, minProfit, group, profit);

        // Selecting ith group;
        if((size + group[i]) <= n)
            cnt += solve(i+1, min(minProfit, prof+profit[i]), size+group[i], n, minProfit, group, profit);

        return dp[i][prof][size] = cnt % MOD;
    }

public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, n, minProfit, group, profit);
    }
};