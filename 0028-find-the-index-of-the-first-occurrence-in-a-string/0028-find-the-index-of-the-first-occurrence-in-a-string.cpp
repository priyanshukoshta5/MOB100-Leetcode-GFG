class Solution {
public:
    void makeLPS(string& pat, int m, vector<int>& lps){
        int len = 0;
        lps[0] = 0;
        int i = 1;
        
        while(i < m)
        {
            if(pat[i] == pat[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if(len != 0)
                    len = lps[len-1];
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        
        vector<int> lps(m);
        makeLPS(needle, m, lps);
        
        int i = 0;  // for haystack
        int j = 0;  // for needle
        
        while(i < n)
        {
            if(haystack[i] == needle[j])
            {
                i++;
                j++;
                if(j == m)
                return (i-j);
            }
            else if(haystack[i] != needle[j])
            {
                if(j != 0)
                    j = lps[j-1];
                else
                    i++;
            }
        }
        
        return -1;
    }
};