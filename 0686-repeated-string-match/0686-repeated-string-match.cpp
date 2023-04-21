class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n = a.length();
        int m = b.length();
        for(int k=0; k<n; k++)
        {
            int i = k, j = 0;
            int cnt = 1;
            while(true)
            {
                if(a[i] != b[j]) break;
                if(j == m-1) return cnt;
                if(i == n-1) cnt++;
                
                i = (i+1)%n;
                j++;
            }
        }
        return -1;
    }
};