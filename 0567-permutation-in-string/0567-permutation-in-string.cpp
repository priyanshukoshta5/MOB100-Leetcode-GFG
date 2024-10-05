class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length() < s1.length())   
            return false;

        int len = s1.length();
        vector<int> freq1(26, 0);
        for(char ch: s1)
            freq1[ch - 'a']++;
        int cnt = 0;
        for(int i = 0; i < 26; i++)
        {
            if(freq1[i] != 0)
                cnt++;
        }

        vector<int> freq2(26, 0);
        int i = 0;
        for(int j = 0; j < s2.length(); j++)
        {
            int ch = int(s2[j] - 'a');
            if(freq1[ch] > 0)
            {
                freq2[ch]++;
                if(freq1[ch] == freq2[ch])
                    cnt--;
                while(i <= j && freq1[ch] < freq2[ch])
                {
                    if(freq1[s2[i] - 'a'] > 0)
                    {
                        if(freq1[s2[i] - 'a'] == freq2[s2[i] - 'a'])
                            cnt++;
                        freq2[s2[i] - 'a']--;
                    }
                    i++;
                }
                if(cnt == 0)
                    return true;
            }
            else
            {
                while(i <= j)
                {
                    if(freq1[s2[i] - 'a'] > 0)
                    {
                        if(freq1[s2[i] - 'a'] == freq2[s2[i] - 'a'])
                            cnt++;
                        freq2[s2[i] - 'a']--;
                    }
                    i++;
                }
            }
        }

        return false;
    }
};