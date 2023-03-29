class Solution {
private:
    void recursion(vector<int>& nums, int ind, vector<int>& temp, vector<vector<int>>& ans){
        ans.push_back(temp);
        for(int i=ind; i<nums.size(); i++)
        {
            if(i != ind && nums[i] == nums[i-1])
                continue;
            temp.push_back(nums[i]);
            recursion(nums, i+1, temp, ans);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        recursion(nums, 0, temp, ans);
        return ans;
    }
};