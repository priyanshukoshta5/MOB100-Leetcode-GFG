class Solution {
private:
    int dp[101][101];

    bool solve(int i1, string &s1, int i2, string &s2, int i3, string &s3, vector<vector<int>> &dp){
        if(i3 < 0)
            return true;

        if(dp[i1 + 1][i2 + 1] != -1)
            return dp[i1 + 1][i2 + 1];

        int first = false;
        if(i1 >= 0 && s1[i1] == s3[i3])
            first = first || solve(i1 - 1, s1, i2, s2, i3 - 1, s3, dp);

        int second = false;
        if(i2 >= 0 && s2[i2] == s3[i3])
            second = second || solve(i1, s1, i2 - 1, s2, i3 - 1, s3, dp);

        return dp[i1 + 1][i2 + 1] = first || second;
    }

public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();

        if((n1 + n2) != n3)
            return false;

        vector<vector<int>> dp(n1 + 1, vector<int> (n2 + 1, -1));
        
        return solve(n1 - 1, s1, n2 - 1, s2, n3 - 1, s3, dp);
    }
};