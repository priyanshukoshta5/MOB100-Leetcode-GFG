class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> arr;
        arr.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++)
        {
            if(arr.back()[1] >= intervals[i][0])
                arr.back()[1] = max(arr.back()[1], intervals[i][1]);
            else
                arr.push_back(intervals[i]);
        }

        return arr;
    }
};