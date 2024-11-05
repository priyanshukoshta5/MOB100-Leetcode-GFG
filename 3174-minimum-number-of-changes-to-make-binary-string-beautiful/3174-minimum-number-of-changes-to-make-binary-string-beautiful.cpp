class Solution {
public:
    int minChanges(string s) {
        int n = s.length();
        int i = 0;
        int cnt = 0;
        while(i < n)
        {
            int j = i;
            char cur = s[j];
            while(j < n && s[j] == cur)
                j++;
            if((j - i) % 2 != 0)
            {
                cnt++;
                i = j + 1;
            }
            else
            {
                i = j;
            }
        }
        return cnt;
    }
};