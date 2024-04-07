class Solution {
private:
    bool check(int ind, string &s, int open, vector<vector<int>> &dp){
        if(ind == s.length())
            return (open == 0);

        if(dp[ind][open] != -1)
            return dp[ind][open];

        bool flag = false;
        if(s[ind] == '(')
            flag = check(ind + 1, s, open + 1, dp);
        else if(s[ind] == ')' && open > 0)
            flag = check(ind + 1, s, open - 1, dp);
        else if(s[ind] == '*')
        {
            flag = flag || check(ind + 1, s, open + 1, dp);   // make it open '('
            if(open > 0)    // make it close ')'
                flag = flag || check(ind + 1, s, open - 1, dp);
            flag = flag || check(ind + 1, s, open, dp);   // make it empty char ''
        }

        return dp[ind][open] = flag;
    }

public:
    bool checkValidString(string s) {
        vector<vector<int>> dp(s.length(), vector<int> (s.length(), -1));
        return check(0, s, 0, dp);
    }
};