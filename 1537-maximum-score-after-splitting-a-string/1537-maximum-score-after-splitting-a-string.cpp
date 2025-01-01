class Solution {
public:
    int maxScore(string s) {
        int ones = 0;
        int zeros = 0;
        int diff = INT_MIN;
        
        for(int i = 0; i < s.length() - 1; i++)
        {
            (s[i] == '1') ? ones++ : zeros++;
            diff = max(diff, zeros - ones);
        }
        if(s[s.length() - 1] == '1')
            ones++;
        
        return (ones + diff);
    }
};