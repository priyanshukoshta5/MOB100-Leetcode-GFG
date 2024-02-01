class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> ans;

        if(n % 3 != 0)
            return ans;

        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i += 3)
        {
            vector<int> temp = {nums[i], nums[i + 1], nums[i + 2]};
            if((temp[2] - temp[0]) > k)
            {
                ans.clear();
                break;
            }
            ans.push_back(temp);
        }

        return ans;
    }
};