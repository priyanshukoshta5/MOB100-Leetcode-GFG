class Solution {
private:
    int solve(vector<int>& days, int i, vector<int>& costs, int endDate, vector<int>& dp){
        if(i == days.size())
            return 0;

        int ans = INT_MAX;
        if(days[i] <= endDate)
            return solve(days, i + 1, costs, endDate, dp);
        else
        {
            if(dp[i] != -1)
                return dp[i];

            ans = min(ans, costs[0] + solve(days, i + 1, costs, days[i], dp));
            ans = min(ans, costs[1] + solve(days, i + 1, costs, days[i] + 6, dp));
            ans = min(ans, costs[2] + solve(days, i + 1, costs, days[i] + 29, dp));
        }
        return dp[i] = ans;
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), -1);
        return solve(days, 0, costs, -1, dp);
    }
};