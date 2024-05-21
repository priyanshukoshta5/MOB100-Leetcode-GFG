class Solution {
private:
    void dfs(int ind, vector<int> &nums, vector<int> &res, vector<vector<int>> &ans){
        if(ind == nums.size())
        {
            ans.push_back(res);
            return;
        }

        // skip current element
        dfs(ind + 1, nums, res, ans);

        // take current element
        res.push_back(nums[ind]);
        dfs(ind + 1, nums, res, ans);
        res.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> res;
        dfs(0, nums, res, ans);
        return ans;
    }
};