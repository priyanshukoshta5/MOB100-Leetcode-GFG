class Solution {
public:
    string reorganizeString(string s) {
        vector<int> charCounts(26, 0);
        for (char c : s) 
        {
            charCounts[c - 'a']++;
            if (charCounts[c - 'a'] > (s.length() + 1) / 2) 
                return "";
        }

        int maxCount = 0, letter = 0;
        for (int i = 0; i < charCounts.size(); i++) 
        {
            if (charCounts[i] > maxCount) 
            {
                maxCount = charCounts[i];
                letter = i;
            }
        }

        string ans = s;
        int index = 0;

        // Place the most frequent letter
        while (charCounts[letter] != 0) 
        {
            ans[index] = char(letter + 'a');
            index += 2;
            charCounts[letter]--;
        }

        // Place rest of the letters in any order
        for (int i = 0; i < charCounts.size(); i++) 
        {
            while (charCounts[i] > 0) 
            {
                if (index >= s.length()) 
                    index = 1;
                
                ans[index] = char(i + 'a');
                index += 2;
                charCounts[i]--;
            }
        }

        return ans;
    }
};