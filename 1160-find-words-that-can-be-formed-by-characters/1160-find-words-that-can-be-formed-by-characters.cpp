class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> freq(26, 0);
        for(char ch: chars)
            freq[ch - 'a']++;
        
        int ans = 0;
        for(string s: words)
        {
            vector<int> temp(freq.begin(), freq.end());
            bool flag = true;
            for(char ch: s)
            {
                temp[ch - 'a']--;
                if(temp[ch - 'a'] < 0)
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
                ans += s.length();
        }

        return ans;
    }
};