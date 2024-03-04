class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin(), tokens.end());
        
        int maxScore = 0, score = 0;
        int left = 0, right = n - 1;
        while(left <= right)
        {
            if(power >= tokens[left])
            {
                power -= tokens[left];
                score++;
                left++;
                maxScore = max(maxScore, score);
            }
            else if(score > 0)
            {
                power += tokens[right];
                right--;
                score--;
            }
            else
                break;
        }

        return maxScore;
    }
};