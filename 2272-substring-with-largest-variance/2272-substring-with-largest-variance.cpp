class Solution {
public:
    int largestVariance(string s) {
        int n = s.length();
        vector<int> freq(26,0);
        for(char c: s)
            freq[c-'a']++;

        int ans = 0;
        for(char c1 = 'a'; c1 <= 'z'; c1++)
        {
            for(char c2 = 'a'; c2 <= 'z'; c2++)
            {
                if(c1 == c2 || freq[c1-'a'] == 0 || freq[c2-'a'] == 0)
                    continue;

                int f1 = 0, f2 = 0;
                int sum = freq[c2 - 'a'];
                for(char c: s)
                {
                    if(c == c1) 
                        f1++;
                    else if(c == c2)
                    {
                        f2++;
                        sum--;
                    }

                    if(f2 > 0)
                        ans = max(ans, f1 - f2);

                    if(f1 < f2 && sum > 0)
                    {
                        f1 = 0;
                        f2 = 0;
                    }
                }
            }
        }
        return ans;
    }
};