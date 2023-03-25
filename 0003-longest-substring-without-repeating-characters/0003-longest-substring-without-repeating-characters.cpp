class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_map<int,int> mpIndex;
        int i = 0;
        for(int j=0; j<s.length(); j++)
        {
            if(mpIndex.find(s[j]) != mpIndex.end() && i <= mpIndex[s[j]])
                i = mpIndex[s[j]]+1;
            mpIndex[s[j]] = j;
            ans = max(ans, j-i+1);
        }  
        return ans;
    }
};