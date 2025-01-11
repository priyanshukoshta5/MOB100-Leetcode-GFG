class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k > s.length())
            return false;

        unordered_map<char, int> freq;
        for(char ch: s)
            freq[ch]++;
        
        int odds = 0;
        for(auto x: freq)
        {
            if(x.second % 2 == 1)
                odds++;
        }

        if(odds <= k)
            return true;

        return false;
    }
};