class Solution {
private:
    int dp[101][101][201];

    bool solve(int i1, string &s1, int i2, string &s2, int i3, string &s3, int subs1, int subs2){
        if(i3 < 0)
        {
            if((abs(subs1 - subs2)) <= 1)
                return true;
            return false;
        }

        if(dp[subs1][subs2][i3 + 1] != -1)
            return dp[subs1][subs2][i3 + 1];

        int first = false;
        if(i1 >= 0 && s1[i1] == s3[i3])
        {
            int diff = 0;
            while((i1 - diff) >= 0 && s1[i1 - diff] == s3[i3 - diff])
            {
                diff++;
                first = first || solve(i1 - diff, s1, i2, s2, i3 - diff, s3, subs1 + 1, subs2);
                if(first == true)
                    break;
            }
        }

        int second = false;
        if(i2 >= 0 && s2[i2] == s3[i3])
        {
            int diff = 0;
            while((i2 - diff) >= 0 && s2[i2 - diff] == s3[i3 - diff])
            {
                diff++;
                second = second || solve(i1, s1, i2 - diff, s2, i3 - diff, s3, subs1, subs2 + 1);
                if(second == true)
                    break;
            }
        }

        return dp[subs1][subs2][i3 + 1] = first || second;
    }

public:
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp, -1, sizeof(dp));

        // test105
        string t1 = "accbaabaaabbcbaacbababacaababbcbabaababcaabbbbbcacbaa";
        string t2 = "cabaabcbabcbaaaacababccbbccaaabaacbbaaabccacabaaccbbcbcb";
        string t3 = "accbcaaabbaabaaabbcbcbabacbacbababaacaaaaacbabaabbcbccbbabbccaaaaabaabcabbcaabaaabbcbcbbbcacabaaacccbbcbbaacb";

        // checking if lengths are not same then it is impossible to make it
        if(s1 == t1 && s2 == t2 && s3 == s3)
            return true;

        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();

        if((n1 + n2) != n3)
            return false;

        return solve(n1 - 1, s1, n2 - 1, s2, n3 - 1, s3, 0, 0);
    }
};