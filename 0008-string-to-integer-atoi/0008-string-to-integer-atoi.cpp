class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        int sign = 1;
        int i=0;
        int n = s.length();
        while(i < n && s[i] == ' ')
            i++;
        
        if(i < n && (s[i] == '-' || s[i] == '+'))
        {
            if(s[i] == '-') sign = -1;
            if(s[i] == '+') sign = +1;
            i++;
        }
        while(i < n && (s[i]>='0' && s[i]<='9'))
        {
            ans = ans * 10;
            ans = ans + (s[i]-'0');
            if(ans > INT_MAX)
            {
                if(sign > 0)
                    return INT_MAX;
                else
                    return INT_MIN;
            }
            i++;
        }

        return ans * sign;
    }
};