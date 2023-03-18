bool compare(vector<int>& a, vector<int>& b)
{
    if(a[0] == b[0])
        return a[1] < b[1];
    return a[0] < b[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        int len = 1;
        for(auto i: intervals)
        {
            int left = i[0];
            int right = i[1];
            int cur_left = ans[len-1][0];
            int cur_right = ans[len-1][1];

            if(left <= cur_right)
                ans[len-1][1] = max(cur_right, right);
            else
            {
                ans.push_back(i);
                len++;
            }
        }

        return ans;
    }
};