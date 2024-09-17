class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        stringstream ss;

        map<string, int> mp;

        ss << s1;
        string word;
        while(ss >> word)
        {
            // cout<<word<<endl;
            mp[word]++;
        }
        ss.clear();

        vector<string> ans;
        ss << s2;
        while(ss >> word)
        {
            mp[word]++;
        }

        for(auto x: mp)
        {
            if(x.second == 1)
                ans.push_back(x.first);
        }

        return ans;
    }
};