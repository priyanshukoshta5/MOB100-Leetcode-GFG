class Solution {
private:
    void dfs(int n, string &s, map<char, int> &freq, set<string> &st){
        st.insert(s);
        
        if(n == 0)
            return;
        
        for(auto x: freq)
        {
            if(x.second > 0)
            {
                s.push_back(x.first);
                freq[x.first]--;
                dfs(n - 1, s, freq, st);
                s.pop_back();
                freq[x.first]++;
            }
        }

        return;
    }

public:
    int numTilePossibilities(string tiles) {
        map<char, int> freq;
        for(char ch: tiles)
            freq[ch]++;
        
        set<string> st;
        string s = "";
        dfs(tiles.size(), s, freq, st);

        return st.size() - 1;
    }
};