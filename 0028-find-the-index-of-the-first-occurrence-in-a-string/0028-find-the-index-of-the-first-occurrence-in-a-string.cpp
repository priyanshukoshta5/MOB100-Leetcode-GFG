class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        long MOD = 1000000;

        long power = 1;
        for(int i=0; i<m; i++)
            power = (power*31) % MOD;

        long code = 0;
        for(int i=0; i<m; i++)
            code = (code*31 + needle[i]) % MOD;

        long hash = 0;
        for(int i=0; i<n; i++)
        {
            hash = (hash*31 + haystack[i]) % MOD;
            if(i < m-1)
                continue;
            if(i >= m)
                hash = (hash - power*haystack[i-m]) % MOD;

            if(hash < 0)
                hash += MOD;

            if(hash == code)
            {
                if(haystack.substr(i-m+1, m) == needle)
                    return i-m+1;
            }
        }

        return -1;
    }
};