class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        unordered_map<int, int> intervalIndex;
        int interval = 1;
        intervalIndex[0] = interval;
        for(int i = 1; i < nums.size(); i++)
        {
            if(abs(nums[i] - nums[i - 1]) % 2 == 0)
                interval++;
            intervalIndex[i] = interval;
        }

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