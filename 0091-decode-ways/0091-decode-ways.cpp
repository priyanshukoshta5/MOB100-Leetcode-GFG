class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n + 1, 0);
        dp[n] = 1;
        for(int i = n - 1; i >= 0; i--)
        {
            if(s[i] == '0')
                continue;
            
            // single digit
            int val = s[i] - '0';
            dp[i] += dp[i + 1];

            // double digit
            if((i + 1) < n)
            {
                val = (s[i] - '0') * 10 + (s[i + 1] - '0');
                if(val <= 26)
                    dp[i] += dp[i + 2];
            }
        }
        return dp[0];
    }
};