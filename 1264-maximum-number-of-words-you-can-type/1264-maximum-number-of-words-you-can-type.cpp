class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        bool broken[26] = {false};
        for(char c: brokenLetters)
            broken[c - 'a'] = true;

        stringstream ss(text);
        string word;
        
        int cnt = 0;
        while(ss >> word){
            bool flag = true;
            for(char c: word){
                if(broken[c - 'a'] == true){
                    flag = false;
                    break;
                }
            }
            if(flag)
                cnt++;
        }
        
        return cnt;
    }
};