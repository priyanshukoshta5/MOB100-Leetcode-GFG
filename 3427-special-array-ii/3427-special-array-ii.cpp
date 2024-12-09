class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        unordered_map<int, int> intervalIndex;
        vector<vector<int>> intervals;
        intervals.push_back({0, 0});
        intervalIndex[0] = intervals.size();
        for(int i = 1; i < nums.size(); i++)
        {
            if(abs(nums[i] - nums[i - 1]) % 2 == 0)
                intervals.push_back({i, i});
            else
                intervals.back()[1] = i;
            
            intervalIndex[i] = intervals.size();
        }

        // for(auto x: intervals)
        //     cout<<x[0]<<" "<<x[1]<<endl;

        vector<bool> ans;
        for(auto q: queries)
        {
            int left = intervalIndex[q[0]];
            int right = intervalIndex[q[1]];
            ans.push_back(left == right);
        }

        return ans;
    }
};