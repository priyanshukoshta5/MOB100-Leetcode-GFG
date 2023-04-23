class Solution {
private:
    long dp[100001];
    long MOD = 1e9 + 7;

    int solve(string& s, int k, int i){
        if(i == s.length()) 
            return 1;
        if(s[i] == '0') 
            return 0;
        if(dp[i] != -1) 
            return dp[i];

        int ans = 0;
        long num = 0;
        for (int j = i; j < s.size(); j++) 
        {
            num = num * 10 + s[j] - '0';
            if (num > k) break;
            ans = (ans + solve(s, k, j + 1)) % MOD;
        }

        return dp[i] = ans;
    }

public:
    int numberOfArrays(string s, int k) {
        // Not completely mine
        memset(dp, -1, sizeof(dp));
        return solve(s, k, 0);
    }
};