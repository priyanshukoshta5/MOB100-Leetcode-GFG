class Solution {
public:
    int longestPalindrome(string s) {
        map<int, int> freq;
        for(char ch: s)
            freq[ch]++;
        
        int ans = 0;
        bool flag = 0;
        for(auto x: freq)
        {
            ans += (x.second / 2) * 2;
            flag = flag | (x.second % 2 == 1);
        }

        return ans + flag;
    }
};