class Solution {
private:
    int solve(int len, int n, int size, vector<vector<int>> &dp){
        if(len > n)
            return n;
        if(len == n)
            return 0;
        if(dp[len][size] != -1)
            return dp[len][size];
        
        // copy
        int ans1 = n;
        if(len != size)
            ans1 = 1 + solve(len, n, len, dp);

        // paste
        int ans2 = 1 + solve(len + size, n, size, dp);

        return dp[len][size] = min(ans1, ans2);
    }

public:
    int minSteps(int n) {
        if(n == 1)
            return 0;
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        return 1 + solve(1, n, 1, dp);
    }
};