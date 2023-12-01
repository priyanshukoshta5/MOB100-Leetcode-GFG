class Solution {
private:
    char getNextChar(int &i, int &j, vector<string> &words){
        if(words[i].length() == j)  // if we reached to the end of words[i]
        {
            i++;
            j = 0;
        }
        if(i == words.size())       // if we reached to the end of vector words
            return ' ';
        
        char ch = words[i][j];
        j++;
        return ch;
    }

public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        int i1 = 0, i2 = 0;
        int j1 = 0, j2 = 0;
        while(i1 < n1 && i2 < n2)
        {
            char c1 = getNextChar(i1, j1, word1);
            char c2 = getNextChar(i2, j2, word2);
            if(c1 != c2)
                return false;
        }
        return true;
    }
};