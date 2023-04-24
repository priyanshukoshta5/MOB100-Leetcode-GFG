class Solution {
public:
    int compareVersion(string version1, string version2) {
        int v1 = 0;
        int v2 = 0;
        int i = 0;
        int j = 0;
        while(i < version1.length() || j < version2.length())
        {
            if(i < version1.length())
            {
                while(i < version1.length() && version1[i] != '.')
                {
                    v1 = v1 * 10;
                    v1 = v1 + (version1[i]-'0');
                    i++;
                }
                i++;
            }
            if(j < version2.length())
            {
                while(j < version2.length() && version2[j] != '.')
                {
                    v2 = v2 * 10;
                    v2 = v2 + (version2[j]-'0');
                    j++;
                }
                j++;
            }

            if(v1 < v2) return -1;
            if(v1 > v2) return 1;
            v1 = v2 = 0;
        }
        return 0;
    }
};