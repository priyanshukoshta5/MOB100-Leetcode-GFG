class Solution {
public:
    bool isVowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }

    int maxVowels(string s, int k) {
        int ans = 0;
        int vowels = 0;
        int i=0, j=0; // i is the start and j is the end of the window
        while(j < s.length())
        {
            // if s[j] is a vowel add it to the Vowel count
            if(isVowel(s[j]))
                vowels++;
            
            // window size hit so compute answer
            if((j-i+1) == k)
            {
                ans = max(ans, vowels);
                
                // if s[i] is a vowel remove it from the Vowel count and shift window
                if(isVowel(s[i]))
                    vowels--;
                i++;
            }
            j++;
        }
        return ans;
    }
};