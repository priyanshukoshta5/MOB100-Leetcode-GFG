class Solution {
private:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();

        vector<int> prefix(n + 1, 0); // shifting by 1 index
        for(int i = 0; i < n; i++)
        {
            if(isVowel(words[i][0]) && isVowel(words[i].back()))
                prefix[i + 1]++;
            prefix[i + 1] += prefix[i];
        }

        vector<int> ans;
        for(auto q: queries)
            ans.push_back(prefix[q[1] + 1] - prefix[q[0]]);

        return ans;
    }
};