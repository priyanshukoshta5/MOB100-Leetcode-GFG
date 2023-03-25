class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_map<int,int> freq;
        int i = 0;
        for(int j=0; j<s.length(); j++)
        {
            freq[s[j]]++;
            while(freq[s[j]] > 1)
            {
                freq[s[i]]--;
                i++;
            }
            ans = max(ans, j-i+1);
        }  
        return ans;
    }
};