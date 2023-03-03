class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=0, j=0;
        queue<int> q;
        while(i<haystack.length())
        {
            if(haystack[i] == needle[0])
                q.push(i);
            if(haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            else
            {
                if(!q.empty())
                {
                    i = q.front()+1;
                    q.pop();
                    j = 1;
                }
                else
                {
                    i++;
                    j = 0;
                }
            }
            if(j == needle.length())
                return (i-j);
        }
        return -1;
    }
};