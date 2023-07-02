class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.length();
        vector<bool> dp(len+1, false);

        // Base Case
        dp[len] = true;

        for(int i = len-1; i >= 0; i--)
        {
            for(string w: wordDict)
            {
                // if there are enough characters to compare + comparing the word w with string starting from i;
                if((i + w.length()) <= len && s.substr(i, w.length()) == w)
                    dp[i] = dp[i + w.length()];
                if(dp[i] == true)       // We dont want to check if satisfied for a case
                    break;
            }
        }

        return dp[0];
    }
};