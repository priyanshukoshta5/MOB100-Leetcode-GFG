class Solution {
private:
    bool isValid(vector<int> &wordFreq, vector<int> &availableFreq){
        for(int i = 0; i < 26; i++)
            if(availableFreq[i] < wordFreq[i])
                return false;
        return true;
    }

    int solve(int ind, vector<vector<int>> &wordsFreq, vector<int> &availableFreq, vector<int> &score){
        if(ind == -1)
            return 0;

        int notTake = solve(ind - 1, wordsFreq, availableFreq, score);

        int take = 0;
        if(isValid(wordsFreq[ind], availableFreq))
        {
            int wordScore = 0;
            for(int i = 0; i < 26; i++)
            {
                wordScore += (wordsFreq[ind][i] * score[i]);
                availableFreq[i] -= wordsFreq[ind][i];
            }

            // cout<<ind<<" "<<wordScore<<endl;
            take = wordScore + solve(ind - 1, wordsFreq, availableFreq, score);

            for(int i = 0; i < 26; i++)
            {
                wordScore += (wordsFreq[ind][i] * score[i]);
                availableFreq[i] += wordsFreq[ind][i];
            }
        }

        return max(notTake, take);
    }

public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> availableFreq(26, 0);
        for(char c: letters)
            availableFreq[c - 'a']++;
        
        vector<vector<int>> wordsFreq;
        for(string w: words)
        {
            vector<int> temp(26, 0);
            for(char c: w)
                temp[c - 'a']++;
            wordsFreq.push_back(temp);
        }

        return solve(words.size() - 1, wordsFreq, availableFreq, score);
    }
};