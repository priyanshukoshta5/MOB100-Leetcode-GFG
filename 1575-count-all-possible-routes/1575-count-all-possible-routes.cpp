// Recursion + Memoization

class Solution {
private:
    int MOD = 1e9+7;

    int solve(int ind, int fuel, int finish, vector<int>& locations, vector<vector<int>> &dp){
        if(dp[ind][fuel] != -1)
            return dp[ind][fuel];
        
        long long cnt = 0;

        if(ind == finish)
            cnt = 1;

        for(int loc = 0; loc < locations.size(); loc++)
        {
            int fuelReq = abs(locations[loc] - locations[ind]);
            if(loc != ind && fuelReq <= fuel)
            {
                cnt += solve(loc, fuel - fuelReq, finish, locations, dp);
                cnt %= MOD;
            }
        }

        return dp[ind][fuel] = cnt;
    }

public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        vector<vector<int>> dp(locations.size(), vector<int> (fuel+1, -1));
        return solve(start, fuel, finish, locations, dp);
    }
};