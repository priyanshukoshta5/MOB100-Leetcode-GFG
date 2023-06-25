// Tabulation DP, Bottom - Up

class Solution {
private:
    int MOD = 1e9+7;
    
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        
        vector<vector<int>> dp(n, vector<int> (fuel+1));
        for(int f = 0; f <= fuel; f++)
            dp[finish][f] = 1;
        
        for(int f = 0; f <= fuel; f++)
        {
            for(int ind = 0; ind < n; ind++)
            {
                for(int loc = 0; loc < n; loc++)
                {
                    int fuelReq = abs(locations[loc] - locations[ind]);
                    if(loc != ind && fuelReq <= f)
                    {
                        dp[ind][f] += dp[loc][f - fuelReq];
                        dp[ind][f] %= MOD;
                    }
                }
            }
        }
        
        return dp[start][fuel];
    }
};