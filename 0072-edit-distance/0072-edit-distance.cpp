class Solution {
private:
    int solve(string& word1, int i, string& word2, int j, vector<vector<int>> &dp){
        if(i < 0)
            return j+1;
        if(j < 0)
            return i+1;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(word1[i] == word2[j])
            return dp[i][j] = solve(word1, i-1, word2, j-1, dp);
        
        return dp[i][j] = 1 + min(solve(word1, i-1, word2, j, dp),
                                  min(solve(word1, i, word2, j-1, dp),
                                      solve(word1, i-1, word2, j-1, dp)));
    }
    
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return solve(word1, n-1, word2, m-1, dp);
    }
};