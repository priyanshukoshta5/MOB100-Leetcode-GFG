class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        string temp;
        for(string s: strs)
        {
            temp = getit(s);
            groups[temp].push_back(s);
        }

        vector<vector<string>> ans;
        for(auto x: groups)
            ans.push_back(x.second);

        return ans;
    }

    string getit(string s)
    {
        map<char, int> freq;
        for(auto c: s)
            freq[c]++;

        string coded;
        for(auto x: freq)
        {
            coded.push_back(x.first);
            coded += to_string(x.second);
        }

        return coded;
    }
};