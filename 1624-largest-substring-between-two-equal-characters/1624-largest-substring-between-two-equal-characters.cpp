class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> startPos(26, 1e4); 
        int ans = -1;
        for(int i = 0; i < s.length(); i++)
        {
            if(startPos[s[i] - 'a'] == 1e4)
                startPos[s[i] - 'a'] = i;
            else
                ans = max(ans, i - startPos[s[i] - 'a'] - 1);
        }
        return ans;
    }
};