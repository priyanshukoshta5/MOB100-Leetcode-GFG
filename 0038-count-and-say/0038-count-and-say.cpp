class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for(int i=2; i<=n; i++)
        {
            string temp = "";
            int cnt = 0;
            char ch = ' ';
            for(char c: ans)
            {
                if(c == ch)
                    cnt++;
                else
                {
                    if(cnt != 0)
                    {
                        temp += (cnt+'0');
                        temp += ch;
                    }
                    ch = c;
                    cnt = 1;
                }
            }
            temp += (cnt+'0');
            temp += ch;
            ans = temp;
        }
        return ans;
    }
};