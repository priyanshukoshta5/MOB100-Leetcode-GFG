class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int cnt = 0, i, j;
        for(int k = 0; k < n; k++)
        {
            // odd length palindrome
            i = j = k;
            while(i >= 0 && j < n && s[i] == s[j])
            {
                cnt++;
                i--;
                j++;
            }

            // even length palindrome
            if(k == 0 || s[k - 1] != s[k])
                continue;
            i = k - 1;
            j = k;
            while(i >= 0 && j < n && s[i] == s[j])
            {
                cnt++;
                i--;
                j++;
            }
        }
        return cnt;
    }
};