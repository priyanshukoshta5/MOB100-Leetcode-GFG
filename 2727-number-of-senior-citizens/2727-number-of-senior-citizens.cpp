class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;
        for(string s: details)
        {
            if((s[11]-'0')*10 + (s[12]-'0') > 60)
                cnt++;
        }
        return cnt;
    }
};