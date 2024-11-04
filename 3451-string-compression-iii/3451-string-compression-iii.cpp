class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int i = 0;
        while(i < word.length())
        {
            char ch = word[i];
            int cnt = 0;
            while(i < word.length() && word[i] == ch)
            {
                cnt++;
                i++;
            }
            while(cnt > 0)
            {
                comp.append(to_string(min(cnt, 9)));
                comp.push_back(ch);
                cnt = max(0, cnt - 9);
            }
        }
        return comp;
    }
};