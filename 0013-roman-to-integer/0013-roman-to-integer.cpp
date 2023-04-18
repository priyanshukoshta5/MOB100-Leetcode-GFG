class Solution {
public:
    int romanToInt(string s) {
        map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        
        int num = 0;
        char ch;
        int cnt = 0;
        int i=0;
        while(i < s.length())
        {
            ch = s[i];
            cnt = 0;
            while(i<s.length() && s[i] == ch)
            {
                cnt++;
                i++;
            }
            
            if(i<s.length() && mp[s[i]] > mp[ch])
                num -= cnt*mp[ch];
            else
                num += cnt*mp[ch];
        }
        
        return num;
    }
};