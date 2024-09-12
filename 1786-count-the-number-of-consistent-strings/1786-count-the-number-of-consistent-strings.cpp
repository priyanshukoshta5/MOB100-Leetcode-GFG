class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> valid(26, 0);
        for(char ch: allowed)
            valid[ch - 'a'] = true;
        
        int cnt = 0;
        for(string s: words)
        {
            bool flag = true;
            for(char ch: s)
            {
                if(!valid[ch - 'a'])
                {
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