class Solution {
public:
    int minimumLength(string s) {
        int pre = 0, suf = s.length() - 1;
        while(pre < suf)
        {
            if(s[pre] != s[suf])
                break;
            
            char ch = s[pre];
            while(pre <= suf && s[pre] == ch)
                pre++;
            while(pre <= suf && s[suf] == ch)
                suf--;
            // cout<<pre<<" "<<suf<<endl;
        }
        return (suf - pre + 1);
    }
};