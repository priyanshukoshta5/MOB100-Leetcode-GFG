class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int i = 0;
        while(i < s.length())
        {
            ans.push_back(s[i]);
            if(i > 0 && s[i - 1] == s[i])
            {
                char ch = s[i];
                while(i < s.length() && s[i] == ch)
                    i++;
            }
            else
                i++;
        }
        return ans;
    }
};