class Solution {
private:
    void getAll(int ind, vector<int>& nums, vector<vector<int>>& ans){
        if(ind == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i=ind; i<nums.size(); i++)
        {
            swap(nums[i], nums[ind]);
            getAll(ind+1, nums, ans);
            swap(nums[i], nums[ind]);
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getAll(0, nums, ans);
        return ans;
    }
};