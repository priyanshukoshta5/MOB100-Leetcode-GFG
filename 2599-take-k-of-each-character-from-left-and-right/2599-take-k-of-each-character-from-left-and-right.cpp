class Solution {
public:
    int takeCharacters(string s, int k) {
        if(k == 0)
            return 0;

        int n = s.length();

        map<pair<char, int>, int> tempPost;
        vector<int> freq(26, 0);
        for(int i = n - 1; i >= 0; i--)
        {
            freq[s[i] - 'a']++;
            // cout<<s[i]<<" "<<freq[s[i] - 'a']<<endl;
            tempPost[{s[i], freq[s[i] - 'a']}] = i;
        }

        // checking the edge case
        for(int i = 0; i < 3; i++)
        {
            // cout<<i<<" "<<freq[i]<<endl;
            if(freq[i] < k)
                return -1;
        }

        int ans = n;
        vector<int> newFreq(26, 0);
        for(int i = -1; i < n; i++)
        {
            // i == -1, special case where only RHS is removed
            if(i >= 0)
                newFreq[s[i] - 'a']++;
            int rightMin = n;
            for(int c = 0; c < 3; c++)
            {
                // cout<<char('a' + c)<<" "<<k - newFreq[c]<<endl;
                if((k - newFreq[c]) > 0)
                {
                    rightMin = min(rightMin, tempPost[{'a' + c, k - newFreq[c]}]);
                }
            }
            // cout<<(i + 1)<<" "<<rightMin<<" "<<(n - rightMin)<<" = "<<(i + 1) + (n - rightMin)<<endl;
            ans = min(ans, (i + 1) + (n - rightMin));
        }

        return ans;
    }
};