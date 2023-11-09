class Solution {
private:
    int MOD = 1e9+7;

public:
    int countHomogenous(string s) {
        long long int ans = 0;
        int i = 0;
        while(i < s.length())
        {
            long long int cnt = 0;
            char ch = s[i];
            while(i < s.length() && s[i] == ch)
            {
                cnt++;
                i++;
            }
            ans += (cnt * (cnt + 1)) / 2;
            ans %= MOD;
        }
        return (int)ans;
    }
};