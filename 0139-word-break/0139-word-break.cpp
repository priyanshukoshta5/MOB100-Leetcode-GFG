class Solution {
private:
    bool wordBreak(int ind, string& s, set<string> &st, vector<int> &dp){
        if(ind == s.length())
            return true;
        if(dp[ind] != -1)
            return dp[ind];
        
        string str = "";
        for(int i = ind; i < s.length(); i++)
        {
            str.push_back(s[i]);
            if(st.find(str) != st.end())
            {
                if(wordBreak(i+1, s, st, dp) == true)
                    return dp[ind] = true;
            }
        }
        
        return dp[ind] = false;
    }
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for(string s: wordDict)
            st.insert(s);
        
        vector<int> dp(s.length(), -1);
        return wordBreak(0, s, st, dp);
    }
};