class Solution {
private:
    int solve(int i, char prev, string &s, int k, vector<vector<int>> &dp){
        if(i == s.length())
            return 0;
        if(dp[i][prev - 'a'] != -1)
            return dp[i][prev - 'a'];
        
        int notTake = solve(i + 1, prev, s, k, dp);
        int take = 0;
        if(abs(s[i] - prev) <= k)
            take = 1 + solve(i + 1, s[i], s, k, dp);

        return dp[i][prev - 'a'] = max(notTake, take);
    }

public:
    int longestIdealString(string s, int k) {
        vector<vector<int>> dp(s.length(), vector<int> (26, -1));
        int ans = 1;
        for(int i = 0; i < s.length(); i++)
            ans = max(ans, 1 + solve(i + 1, s[i], s, k, dp));
        return ans;
    }
};