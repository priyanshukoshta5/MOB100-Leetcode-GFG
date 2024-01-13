class Solution {
public:
    int minSteps(string s, string t) {
        int freq[26] = {0};
        for(char ch: t) freq[ch - 'a']++;
        for(char ch: s) freq[ch - 'a']--;
        int a = 0, b = 0;
        for(int i = 0; i < 26; i++)
        {
            if(freq[i] > 0) a += freq[i];
            else  b += abs(freq[i]);
        }
        return min(a, b);
    }
};