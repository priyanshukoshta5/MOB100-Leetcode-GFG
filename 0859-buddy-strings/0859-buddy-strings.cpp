class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length() != goal.length())
            return false;
        
        int freq[26] = {0};
        int cnt = 0, j = -1;
        for(int i = 0; i < s.length(); i++)
        {
            freq[s[i]-'a']++;
            if(s[i] != goal[i])
            {
                cnt++;
                if(cnt == 1)
                    j = i;
                else if(cnt == 2)
                {
                    if(s[i] != goal[j] || s[j] != goal[i])
                        return false;
                }
                else if(cnt > 2)
                    return false;
            }
        }
        if(cnt == 1)
            return false;
        if(cnt == 2)
            return true;
        
        for(int i = 0; i < 26; i++)
            if(freq[i] > 1)
                return true;
        return false;
    }
};