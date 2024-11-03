class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length())
            return false;
        
        int n = s.length();
        for(int p = 0; p < n; p++)
        {
            if(s[0] == goal[p])
            {
                int i = 0, j = p;
                while(i < n && s[i] == goal[j])
                {
                    i = i + 1;
                    j = (j + 1) % n;
                }
                if(i == n)
                    return true;
            }
        }
        
        return false;
    }
};