class Solution {
private:
    int solve(string& text1, int i, string& text2, int j, vector<vector<int>> &dp){
        if(i == -1 || j == -1)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        // not taking anyone
        int res = max(solve(text1, i-1, text2, j, dp), solve(text1, i, text2, j-1, dp));
        
        if(text1[i] == text2[j])
            res = max(res, 1 + solve(text1, i-1, text2, j-1, dp));
        
        return dp[i][j] = res;
    }
    
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length()+1, vector<int> (text2.length()+1, -1));
        return solve(text1, text1.length()-1, text2, text2.length()-1, dp);
    }
};