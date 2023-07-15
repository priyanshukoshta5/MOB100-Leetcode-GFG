class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        
        sort(events.begin(), events.end());    //  sort increasing with START_DATE
        vector<int> startDays;
        for(auto e: events)
            startDays.push_back(e[0]);

        vector<vector<int>> dp(n+1, vector<int> (k+1, 0));
        
        for(int ind = n-1; ind >= 0; ind--)
        {
            for(int e = 1; e <= k; e++)
            {
                int notTake = 0 + dp[ind + 1][e];

                int start = events[ind][0];
                int end = events[ind][1];
                int value = events[ind][2];

                int take = 0;
                if(e == 1)
                    take = value;
                else
                {
                    auto it = lower_bound(startDays.begin() + ind, startDays.end(), end+1);
                    int i = it - startDays.begin(); 

                    int temp = value + dp[i][e-1];
                    take = max(take, temp);
                }

                dp[ind][e] = max(take, notTake);
            }
        }

        return dp[0][k];
    }
};