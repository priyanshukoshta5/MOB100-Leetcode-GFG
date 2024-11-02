class Solution {
public:
    bool isCircularSentence(string sentence) {
        stringstream s(sentence);
        string word;
        s >> word;
        char lastChar = word[word.length() - 1];
        while(s >> word)
        {
            if(word[0] != lastChar)
                return false;
            lastChar = word[word.length() - 1];
        }
        if(sentence[0] != lastChar)
            return false;
        return true;
    }
};