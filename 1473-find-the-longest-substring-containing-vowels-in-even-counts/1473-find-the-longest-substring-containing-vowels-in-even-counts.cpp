class Solution {
private:
    void flipbit(string &mask, int i){
        if(mask[i] == '1')
            mask[i] = '0';
        else 
            mask[i] = '1';
        return;
    }

    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

public:
    int findTheLongestSubstring(string s) {
        string mask = "00000";
        map<char, int> code = {{'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}};
        int ans = 0;
        map<string, int> mp;
        mp[mask] = -1;
        for(int i = 0; i < s.length(); i++)
        {
            if(isVowel(s[i]))
                flipbit(mask, code[s[i]]);

            if(mp.find(mask) == mp.end())
                mp[mask] = i;
            else
                ans = max(ans, i - mp[mask]);

            // cout<<i<<" "<<mask<<" "<<ans<<endl;
        }

        // for(auto x: mp)
        //     cout<<x.first<<" "<<x.second<<endl;
        return ans;
    }
};