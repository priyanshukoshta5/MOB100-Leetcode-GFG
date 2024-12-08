class Solution {
private:
    int binSearch(int ind, vector<vector<int>> &events){
        int x = events[ind][1];
        int l = ind + 1, r = events.size() - 1;
        while(l <= r)
        {
            int m = l + (r - l) / 2;
            if(events[m][0] > x)
                r = m - 1;
            else
                l = m + 1;
        }
        return l;
    }

    // int solve(int ops, int ind, vector<vector<int>> &events, vector<int> &dp){
    //     if(ops == 0)
    //         return 0;
    //     if(dp[ind] != -1)
    //         return dp[ind];
        
    //     int pos = binSearch(ind, events);
    //     dp[ind] = events[ind][2];
    //     for(int i = pos; i < events.size(); i++)
    //         dp[ind] = max(dp[ind], events[ind][2] + solve(ops - 1, i, events, dp));

    //     return dp[ind];
    // }

public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();

        sort(events.begin(), events.end());
        // for(auto i: events)
        //     cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;

        // vector<int> dp(n, -1);
        vector<int> postMax(n, -1);
        postMax[n - 1] = events[n - 1][2];
        int ans = events[n - 1][2];
        for(int i = n - 2; i >= 0; i--)
        {
            // solve(1, i, events, dp);
            // cout<<i<<" "<<dp[i]<<endl;
            int pos = binSearch(i, events);
            if(pos < n)
                ans = max(ans, events[i][2] + postMax[pos]);
            else
                ans = max(ans, events[i][2]);

            postMax[i] = max(events[i][2], postMax[i + 1]);
        }

        // return *max_element(dp.begin(), dp.end());
        return ans;
    }
};