class Solution {
private:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

public:
    bool halvesAreAlike(string s) {
        int n = s.length();
        if(n % 2 == 1)
            return false;

        int cnt = 0;
        char ch;
        for(int i = 0, j = n/2; j < n; i++, j++)
        {
            ch = tolower(s[i]);
            if(isVowel(ch))
                cnt++;
            
            ch = tolower(s[j]);
            if(isVowel(ch))
                cnt--;
        }

        return cnt == 0;
    }
};