class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mpIndex(256, -1);
        int ans = 0;
        int i = 0;
        for(int j=0; j<s.length(); j++)
        {
            // Just jumping the i(left) pointer -> O(N) time complexity only
            if(mpIndex[s[j]] != -1)
                i = max(i, mpIndex[s[j]]+1);
            mpIndex[s[j]] = j;
            ans = max(ans, j-i+1);
        }  
        return ans;
    }
};