class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int extraClose = 0;
        for(char ch: s)
        {
            if(ch == '(')
                open++;
            else if(ch == ')')
            {
                if(open == 0)
                    extraClose++;
                else
                    open--;
            }
        }
        return open + extraClose;;
    }
};