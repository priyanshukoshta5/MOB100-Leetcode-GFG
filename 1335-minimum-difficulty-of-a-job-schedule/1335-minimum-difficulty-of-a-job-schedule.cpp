int dp[301][1001][11];

class Solution {
private:
    int solve(int ind, int d, int prevMaxDiff, vector<int> &diffs){
        if(ind == diffs.size())
        {
            if(d == 0)
                return prevMaxDiff;
            else
                return 1e7;
        }
        if(d <= 0)
            return 1e7;
        if(dp[ind][prevMaxDiff][d] != -1)
            return dp[ind][prevMaxDiff][d];
        
        // 'ind' is not the last job of the day 'd'
        int res1 = solve(ind + 1, d, max(prevMaxDiff, diffs[ind]), diffs);

        // 'ind' is the last job of the day 'd'
        int res2 = max(prevMaxDiff, diffs[ind]) + solve(ind + 1, d - 1, 0, diffs);

        return dp[ind][prevMaxDiff][d] = min(res1, res2);
    }

public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n < d)
            return -1;
        
        memset(dp, -1, sizeof(dp));
        return solve(0, d, 0, jobDifficulty);
    }
};