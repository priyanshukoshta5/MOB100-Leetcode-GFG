class Solution {
private:
    int solve(int ind, string &s, set<string> &st){
        if(ind == s.length())
        {
            // cout<<"END\n";
            return 0;
        }
        
        string subString = "";
        int res = 0;
        for(int i = ind; i < s.length(); i++)
        {
            subString.push_back(s[i]);
            if(st.find(subString) == st.end())
            {
                st.insert(subString);
                res = max(res, 1 + solve(i + 1, s, st));
                st.erase(subString);
            }
        }

        return res;
    }

public:
    int maxUniqueSplit(string s) {
        set<string> st;
        return solve(0, s, st);
    }
};