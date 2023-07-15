class Solution {
private:
    int solve(int ind, int k, vector<vector<int>>& events, vector<int>& startDays, vector<vector<int>>& dp){
        if(ind == events.size())
            return 0;
        if(dp[ind][k] != -1)
            return dp[ind][k];

        int notTake = 0 + solve(ind + 1, k, events, startDays, dp);

        int start = events[ind][0];
        int end = events[ind][1];
        int value = events[ind][2];

        int take = 0;
        if(k == 1)
            take = value;
        else
        {
            int i = lower_bound(startDays.begin() + ind, startDays.end(), end+1) - startDays.begin();
            int temp = value + solve(i, k-1, events, startDays, dp);
            take = max(take, temp);
        }

        return dp[ind][k] = max(take, notTake);
    }

public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());    //  sort increasing with START_DATE
        vector<int> startDays;
        for(auto e: events)
            startDays.push_back(e[0]);

        vector<vector<int>> dp(events.size(), vector<int> (k+1, -1));

        return solve(0, k, events, startDays, dp);
    }
};