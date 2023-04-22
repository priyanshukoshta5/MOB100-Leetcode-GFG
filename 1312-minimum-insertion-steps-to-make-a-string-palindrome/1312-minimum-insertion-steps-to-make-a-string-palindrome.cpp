class Solution {
private:
    int dp[501][501];

    int solve(string& s, int i, int j){
        if(i >= j) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = INT_MAX;
        if(s[i] == s[j])
            ans = min(ans, solve(s, i+1, j-1));
        else
        {
            // insert at start
            ans = min(ans, 1 + solve(s, i, j-1));
            // insert at end
            ans = min(ans, 1 + solve(s, i+1, j));
        }

        return dp[i][j] = ans;
    }

public:
    int minInsertions(string s) {
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, s.length()-1);
    }
};