class Solution {
public:
    int bestClosingTime(string customers) {
        int yAfter = count(customers.begin(), customers.end(), 'Y');
        int nBefore = 0;

        int minPanalty = INT_MAX;
        int ansHour = 0;
        for(int i = 0; i <= customers.size(); i++)
        {
            if(yAfter + nBefore < minPanalty)
            {
                minPanalty = yAfter + nBefore;
                ansHour = i;
            }
            if(i == customers.size())
                break;

            if(customers[i] == 'Y')
                yAfter--;
            else
                nBefore++;
        }

        return ansHour;
    }
};