class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<vector<int>> merged;
        for(vector<int> interval: meetings){
            if(merged.size() == 0 || merged.back()[1] < interval[0])
                merged.push_back(interval);
            else
                merged.back()[1] = max(merged.back()[1], interval[1]);
        }

        int ans = 0;

        for(int i = 0; i < merged.size(); i++){
            if(i == 0){
                ans += merged[0][0] - 1;
            }
            else{
                ans += merged[i][0] - merged[i - 1][1] - 1; 
            }
        }
        ans += (days - merged.back()[1]);

        return ans;
    }
};