class Solution {
public:
    int numSteps(string s) {
        if(s.length() == 1)
            return 0;

        int one = count(s.begin(), s.end(), '1');
        if(one == s.length())
            return one + 1;

        reverse(s.begin(), s.end());
        int ops = 0;
        int minI = 0;
        while(minI < s.length() - 1)
        {
            if(s[minI] == '0')
            {
                ops++;
                minI++;
            }
            else
            {
                s[minI] = '0';
                int i = minI + 1;
                while(s[i] == '1')  // will never reach the end
                {
                    s[i] = '0';
                    i++;
                }
                if(i == s.length())
                {
                    ops += (1 + s.length() - minI);
                    break;
                }
                ops += 1 + (i - minI);
                minI = i;
                s[i] = '1';
            }
            // cout<<minI<<" "<<s<<endl;
        }

        return ops;
    }
};