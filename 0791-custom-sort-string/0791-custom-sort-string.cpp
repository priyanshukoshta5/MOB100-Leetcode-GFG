class Solution {
public:
    string customSortString(string order, string s) {
        int n = s.length();

        unordered_map<char, set<char>> mp;
        set<char> temp;
        for(char ch: order)
        {
            mp[ch] = temp;
            temp.insert(ch);
        }

        // selection sort
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                char a = s[i];
                char b = s[j];
                if(mp[a].find(b) != mp[a].end())
                    swap(s[i], s[j]);
            }
        }

        return s;
    }
};