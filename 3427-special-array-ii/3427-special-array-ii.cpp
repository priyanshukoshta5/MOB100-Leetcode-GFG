class Solution {
private:
    int binSearch(int x, vector<vector<int>> &intervals){
        int l = 0, r = intervals.size() - 1;
        while(l <= r)
        {
            int m = l + (r - l) / 2;
            if(x >= intervals[m][0] && x <= intervals[m][1])
                return m;
            else if(x < intervals[m][0])
                r = m - 1;
            else
                l = m + 1;
        }
        return l;
    }

public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<vector<int>> intervals;
        intervals.push_back({0, 0});
        for(int i = 1; i < nums.size(); i++)
        {
            if(abs(nums[i] - nums[i - 1]) % 2 == 0)
                intervals.push_back({i, i});
            else
                intervals.back()[1] = i;
        }

        // for(auto x: intervals)
        //     cout<<x[0]<<" "<<x[1]<<endl;

        vector<bool> ans;
        for(auto q: queries)
        {
            int left = binSearch(q[0], intervals);
            int right = binSearch(q[1], intervals);
            ans.push_back(left == right);
        }

        return ans;
    }
};