class Solution {
private:
    bool isPalindrome(string& s){
        for(int i = 0, j = s.length() - 1; i < j; i++, j--)
            if(s[i] != s[j])
                return false;
        return true;
    }

    void solve(string& s, int ind, vector<string>& temp, vector<vector<string>>& ans){
        if(ind == s.length())
        {
            ans.push_back(temp);
            return;
        }

        string t;
        for(int i = ind; i < s.length(); i++)
        {
            t.push_back(s[i]);
            if(isPalindrome(t))
            {
                temp.push_back(t);
                solve(s, i + 1, temp, ans);
                temp.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(s, 0, temp, ans);
        return ans;
    }
};