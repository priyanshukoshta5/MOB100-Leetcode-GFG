class Solution {
private:
    void solve(int n, int pos, string& s, string temp, unordered_map<string,bool>& dict, vector<string>& ans){
        if(pos == n)
        {
            temp.pop_back();
            ans.push_back(temp);
            return;
        }

        string word;
        for(int i=pos; i<n; i++)
        {
            word.push_back(s[i]);
            if(dict.find(word)!= dict.end())
                solve(n, i+1, s, temp+word+" ", dict, ans);
        }
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> dict;
        for(string st: wordDict)
            dict[st] = true;
        vector<string> ans;
        solve(s.length(), 0, s, "", dict, ans);

        return ans;
    }
};