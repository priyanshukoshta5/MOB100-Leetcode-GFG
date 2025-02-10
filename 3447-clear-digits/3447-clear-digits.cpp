class Solution {
private:
    bool isDigit(char ch){
        return ch >= '0' && ch <= '9';
    }

public:
    string clearDigits(string s) {
        stack<char> stk;
        for(char i: s)
        {
            if(isDigit(i))
            {
                if(!stk.empty())
                    stk.pop();
            }
            else
                stk.push(i);
        }
        string ans = "";
        while(!stk.empty())
        {
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};