class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> freq(26, INT_MAX);
        for(string s: words)
        {
            vector<int> temp(26, 0);
            for(char ch: s)
                temp[ch - 'a']++;
            for(int i = 0; i < 26; i++)
                freq[i] = min(freq[i], temp[i]);
        }

        vector<string> ans;
        for(int i = 0; i < 26; i++)
        {
            char c = ('a' + i);
            string yo;
            yo.push_back(c);
            // cout<<c<<" -> "<<freq[i]<<endl;
            for(int j = 0; j < freq[i]; j++)
                ans.push_back(yo);
        }

        return ans;
    }
};