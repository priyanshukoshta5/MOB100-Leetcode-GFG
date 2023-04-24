class Solution {
public:
    string recur(string str, int n){
        if(n == 0)
            return str;
        
        string temp = "";
        int cnt = 0;
        char ch = ' ';
        for(char c: str)
        {
            if(c == ch)
                cnt++;
            else
            {
                if(cnt != 0)
                {
                    temp = temp + to_string(cnt);
                    temp.push_back(ch);
                }
                ch = c;
                cnt = 1;
            }
        }
        temp = temp + to_string(cnt);
        temp.push_back(ch);
        
        return recur(temp, n-1); 
    }
    
    string countAndSay(int n) {
        return recur("1", n-1);
    }
};