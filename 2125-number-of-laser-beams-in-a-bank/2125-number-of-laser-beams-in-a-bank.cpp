class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prevLasers = 0;
        int ans = 0;
        for(auto &row: bank)
        {
            int currLasers = count(row.begin(), row.end(), '1');
            if(currLasers != 0)
            {
                ans = ans + (prevLasers * currLasers);
                prevLasers = currLasers;
            }
        }
        return ans;
    }
};