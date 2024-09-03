class Solution {
public:
    int getLucky(string s, int k) {
        string code;
        for(char ch: s)
            code.append(to_string(int(ch - 'a' + 1)));
        
        int ans = 0;
        while(k--)
        {
            int res = 0;
            for(char ch: code)
                res += int(ch - '0');
            ans = res;
            code = to_string(res);
        }

        return ans;
    }
};