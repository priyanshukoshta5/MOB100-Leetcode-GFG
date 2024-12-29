class Solution {
private:
    int MOD = 1e9+7;

    int solve(int wordI, int targI, string& target, vector<vector<long long>>& indFreq, vector<vector<int>>& dp){
        if(targI == target.size())
            return 1;

        if(wordI == indFreq.size())
            return 0;

        if(dp[wordI][targI] != -1)
            return dp[wordI][targI];

        // not select wordI
        long long res1 = 1 * solve(wordI + 1, targI, target, indFreq, dp);
        res1 = res1 % MOD;

        // select wordI
        long long res2 = indFreq[wordI][target[targI] - 'a'] * solve(wordI + 1, targI + 1, target, indFreq, dp);
        res2 = res2 % MOD;

        return dp[wordI][targI] = (res1 + res2) % MOD;
    }

public:
    int numWays(vector<string>& words, string target) {
        int n = words.size();
        int len = words[0].length();
        
        vector<vector<long long>> indFreq(len, vector<long long> (26, 0));
        vector<vector<int>> dp(len, vector<int> (target.size(), -1));
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < len; j++)
                indFreq[j][words[i][j] - 'a']++;
        }

        return solve(0, 0, target, indFreq, dp);
    }
};