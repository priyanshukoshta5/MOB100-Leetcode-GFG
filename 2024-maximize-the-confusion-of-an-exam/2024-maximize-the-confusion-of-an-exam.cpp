class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int t = 0, f = 0;
        int i = 0;
        int ans = 1;
        for(int j = 0; j < answerKey.length(); j++)
        {
            if(answerKey[j] == 'T') t++;
            else f++;

            while(t > k && f > k)
            {
                if(answerKey[i] == 'T') t--;
                else f--;
                i++;
            }

            ans = max(ans, j-i+1);
        }
        return ans;
    }
};