class Solution {
private:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        for (auto interval : intervals) {
            // if the list of merged intervals is empty or if the current
            // interval does not overlap with the previous, simply append it.
            if (merged.empty() || merged.back()[1] <= interval[0]) {
                merged.push_back(interval);
            }
            // otherwise, there is overlap, so we merge the current and previous
            // intervals.
            else {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        return merged;
    }

public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> xIntervals, yIntervals;
        for(vector<int> rect: rectangles){
            xIntervals.push_back({rect[0], rect[2]});
            yIntervals.push_back({rect[1], rect[3]});
        }

        vector<vector<int>> xMerged = merge(xIntervals);
        vector<vector<int>> yMerged = merge(yIntervals);

        return xMerged.size() >= 3 || yMerged.size() >= 3;
    }
};