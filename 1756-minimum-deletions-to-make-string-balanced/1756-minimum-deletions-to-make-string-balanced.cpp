class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        int cntA = count(s.begin(), s.end(), 'a');
        int cntB = 0;

        int ans = cntA;
        for(char ch: s)
        {
            if(ch == 'a')
                cntA--;
            else
                cntB++;
            ans = min(ans, cntA + cntB);
        }
        return ans;
    }
};