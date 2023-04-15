class Solution {
public:
    string reverseWords(string s) {
        string ans;
        string temp;
        
        int i=0;
        while(i < s.length())
        {
            while(i < s.length() && s[i] == ' ')
                i++;
            
            if(i<s.length() && s[i] != ' ')
            {
                while(i < s.length() && s[i] != ' ')
                    temp.push_back(s[i++]);
                
                if(ans.length() == 0) 
                    ans = temp;
                else 
                    ans = temp + " " + ans;
            }
            temp.clear();
        }        
        
        return ans;
    }
};