class Solution {
public:
    string longestPalindrome(string s) {
        int len = 0;
        string ans;
        int n = s.length();
        int l, r;
        for(int i=0; i<n; i++)
        {
            l = i;
            r = i;
            while(l >= 0 && r < n && s[l] == s[r])
            {
                if((r-l+1) > len)
                {
                    len = r-l+1;
                    ans = s.substr(l, len);
                }
                l--;
                r++;
            }

            l = i;
            r = i+1;
            while(l >= 0 && r < n && s[l] == s[r])
            {
                if((r-l+1) > len)
                {
                    len = r-l+1;
                    ans = s.substr(l, len);
                }
                l--;
                r++;
            }
        }

        return ans;
    }
};