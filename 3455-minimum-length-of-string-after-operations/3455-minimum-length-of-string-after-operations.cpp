class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> freq;
        for(char ch: s)
            freq[ch]++;
        
        int len = 0;
        for(auto x: freq)
        {
            if(x.second % 2 == 1)
                len += 1;
            else
                len += 2;
        }
        
        return len;
    }
};