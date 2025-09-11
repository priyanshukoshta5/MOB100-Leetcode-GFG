class Solution {
private:
    bool isVowel(char ch){
        string s = "aeiouAEIOU";
        for(char c: s)
            if(ch == c)
                return true;
        return false;
    }

public:
    string sortVowels(string s) {
        vector<char> vowels;
        for(char ch: s){
            if(isVowel(ch))
                vowels.push_back(ch);
        }

        sort(vowels.begin(), vowels.end());

        int i = 0;
        for(int j = 0; j < s.length(); j++){
            if(isVowel(s[j])){
                s[j] = vowels[i];
                i++;
            }
        }

        return s;
    }
};