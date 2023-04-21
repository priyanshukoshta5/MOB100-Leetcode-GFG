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
                if(a[i] != b[j])
                    break;
                
                j++;
                if(j == m)
                    return cnt;
                
                if(i == n-1)
                {
                    cnt++;
                    i = 0;
                }
                else 
                    i++;
            }
            if(j == m)
                return cnt;
        }
        return -1;
    }
};