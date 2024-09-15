class Solution {
private:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

public:
    int findTheLongestSubstring(string s) {
        map<char, int> code = {{'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}};

        int mask = 00000;
        int ans = 0;
        vector<int> mp(10001, -2);
        mp[mask] = -1;

        for(int i = 0; i < s.length(); i++)
        {
            if(isVowel(s[i]))
                mask = mask ^ (1 << code[s[i]]);

            if(mp[mask] == -2)
                mp[mask] = i;
            else
                ans = max(ans, i - mp[mask]);

            // cout<<i<<" "<<mask<<" "<<ans<<" "<<mp[mask]<<endl;
        }
        
        return ans;
    }
};