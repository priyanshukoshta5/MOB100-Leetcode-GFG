class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        int i = 0;
        while(i < num.length())
        {
            while(!s.empty() && k > 0 && s.top() > num[i])
            {
                s.pop();
                k--;
            }
            s.push(num[i]);
            i++;
        }

        while(k > 0 && !s.empty())
        {
            s.pop();
            k--;
        }
        
        string ans = "";
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }

        reverse(ans.begin(), ans.end());

        size_t pos = ans.find_first_not_of('0');
        ans = (pos == std::string::npos) ? "0" : ans.substr(pos);

        return ans;
    }
};