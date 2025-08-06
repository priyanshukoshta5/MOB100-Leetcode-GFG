class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char, int> freq;
        int i = 0, j = 0;
        int ans = 0;
        while(j < s.length()){
            freq[s[j]]++;
            while(i <= j && freq.size() == 3){
                ans = ans + (s.length() - j);
                freq[s[i]]--;
                if(freq[s[i]] == 0)
                    freq.erase(s[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};