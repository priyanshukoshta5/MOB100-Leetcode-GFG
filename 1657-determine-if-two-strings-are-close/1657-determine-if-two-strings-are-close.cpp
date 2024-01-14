class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length())
            return false;
        
        int freq1[26] = {0};
        for(char ch: word1) freq1[ch - 'a']++;
        int freq2[26] = {0};
        for(char ch: word2) freq2[ch - 'a']++;

        // checking that we can use Operation 2, operation 2 require existing chars to swap
        for(int i = 0; i < 26; i++)
        {
            if(freq1[i] == 0 ^ freq2[i] == 0)   // if both are not zero simultaneously
                return false;
        }

        // checking that we can use Operation 2, it require similar number of frequencies of chars
        sort(freq1, freq1 + 26);
        sort(freq2, freq2 + 26);
        for(int i = 0; i < 26; i++)
            if(freq1[i] != freq2[i])
                return false;

        return true;
    }
};