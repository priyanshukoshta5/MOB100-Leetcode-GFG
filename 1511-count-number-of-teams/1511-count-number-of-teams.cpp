class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        
        vector<int> leftLessThan(n), rightLessThan(n);
        vector<int> leftMoreThan(n), rightMoreThan(n);
        for(int i = 0; i < n; i++)
        {
            int lessThan = 0, moreThan = 0;
            for(int j = 0; j < i; j++)
            {
                if(rating[j] < rating[i])
                    lessThan++;
                if(rating[j] > rating[i])
                    moreThan++;
            }
            leftLessThan[i] = lessThan;
            leftMoreThan[i] = moreThan;

            lessThan = moreThan = 0;
            for(int j = i + 1; j < n; j++)
            {
                if(rating[j] < rating[i])
                    lessThan++;
                if(rating[j] > rating[i])
                    moreThan++;
            }
            rightLessThan[i] = lessThan;
            rightMoreThan[i] = moreThan;

            // cout<<i<<" -> "<<leftLessThan[i]<<" "<<leftMoreThan[i]<<" "<<rightLessThan[i]<<" "<<rightMoreThan[i]<<endl;
        }

        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            ans = ans + (leftLessThan[i] * rightMoreThan[i]);
            ans = ans + (leftMoreThan[i] * rightLessThan[i]);
        }

        return ans;
    }
};