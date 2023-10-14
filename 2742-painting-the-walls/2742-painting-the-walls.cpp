class Solution {
private:
    int solve(int ind, int timeLeft, vector<int> &cost, vector<int> &time, vector<vector<int>> &dp){
        if(timeLeft <= 0)       // time over for paid painter
            return 0;
        if(ind < 0)             // paid painter not done full time
            return 1e9;
        if(dp[ind][timeLeft] != -1)
            return dp[ind][timeLeft];

        // not paint
        int notTake = solve(ind - 1, timeLeft, cost, time, dp);

        // paint
        int take = cost[ind] + solve(ind - 1, timeLeft - 1 - time[ind], cost, time, dp);

        return dp[ind][timeLeft] = min(take, notTake);
    }

public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n, vector<int> (n + 1, -1));
        return solve(n - 1, n, cost, time, dp);
    }
};