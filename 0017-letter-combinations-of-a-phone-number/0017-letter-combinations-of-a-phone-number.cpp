class Solution {
private:
    void findAll(int i, string& digits, int n, string& str, unordered_map<char, string> &chars, vector<string> &ans){
        if(i == n)
        {
            ans.push_back(str);
            return;
        }

        for(char ch: chars[digits[i]])
        {
            str.push_back(ch);
            findAll(i+1, digits, n, str, chars, ans);
            str.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size() == 0)
            return ans;
        unordered_map<char, string> chars;
        chars['2'] = "abc";
        chars['3'] = "def";
        chars['4'] = "ghi";
        chars['5'] = "jkl";
        chars['6'] = "mno";
        chars['7'] = "pqrs";
        chars['8'] = "tuv";
        chars['9'] = "wxyz";
        string s;
        findAll(0, digits, digits.size(), s, chars, ans);
        return ans;
    }
};