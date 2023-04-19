class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        for(int i=0; i<strs[0].length(); i++)
        {
            for(string s: strs)
            {
                if(i == s.length() || s[i] != strs[0][i])
                    return ans;
            }
            ans.push_back(strs[0][i]);
        }
        return ans;
    }
};