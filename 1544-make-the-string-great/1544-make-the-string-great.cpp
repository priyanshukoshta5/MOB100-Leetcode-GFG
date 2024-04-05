class Solution {
public:
    string makeGood(string s) {
        stack<char> stk;
        for(char c: s)
        {
            if(stk.size() > 0 && abs(stk.top() - c) == 32)
                stk.pop();
            else
                stk.push(c);
        }
        
        s.clear();
        while(stk.size() > 0)
        {
            s.push_back(stk.top());
            stk.pop();
        }

        reverse(s.begin(), s.end());
        return s;
    }
};