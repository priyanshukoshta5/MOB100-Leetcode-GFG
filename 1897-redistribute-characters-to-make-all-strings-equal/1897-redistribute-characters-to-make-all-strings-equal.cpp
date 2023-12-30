class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> freq(26, 0);
        for(string &s: words)
            for(char &ch: s)
                freq[ch - 'a']++;
        
        for(int &i: freq)
            if(i % words.size() != 0)
                return false;
        
        return true;
    }
};