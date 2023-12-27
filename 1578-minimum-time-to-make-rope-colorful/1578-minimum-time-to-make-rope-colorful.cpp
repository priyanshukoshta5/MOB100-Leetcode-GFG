class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        char prev = '.';
        int prevTime = 0;
        for(int i = 0; i < colors.length(); i++)
        {
            if(colors[i] == prev)
            {
                ans += min(neededTime[i], prevTime);
                prevTime = max(neededTime[i], prevTime);
            }
            else
            {
                prevTime = neededTime[i];
                prev = colors[i];
            }
        }
        return ans;
    }
};