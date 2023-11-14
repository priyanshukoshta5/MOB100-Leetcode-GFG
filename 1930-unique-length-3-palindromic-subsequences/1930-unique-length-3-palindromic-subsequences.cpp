class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<pair<int, int>> occurance(26, {INT_MAX, INT_MIN});
        for(int i = 0; i < s.length(); i++)
        {
            occurance[s[i] - 'a'].first = min(i, occurance[s[i] - 'a'].first);
            occurance[s[i] - 'a'].second = max(i, occurance[s[i] - 'a'].second);
        }

        int cnt = 0;
        for(int c = 0; c < 26; c++)
        {
            auto p = occurance[c];
            if(p.first == INT_MAX)
                continue;

            unordered_set<char> uniq;
            for(int i = p.first + 1; i < p.second; i++)
                uniq.insert(s[i]);
            // cout<<char('a' + c)<<" "<<p.first<<" "<<p.second<<" "<<uniq.size()<<endl;
            cnt += uniq.size();
        }

        return cnt;
    }
};