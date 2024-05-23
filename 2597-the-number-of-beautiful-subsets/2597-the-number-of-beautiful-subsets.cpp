class Solution {
private:
    int subsetsCount = 0;
    void dfs(int ind, vector<int> &nums, int k, vector<int> &temp){
        // cout<<ind<<" ";
        if(ind == nums.size())
        {
            subsetsCount++;
            return;
        }

        // not take
        dfs(ind + 1, nums, k, temp);

        // take
        if(binary_search(temp.begin(), temp.end(), nums[ind] - k) == 0)
        {
            temp.push_back(nums[ind]);
            dfs(ind + 1, nums, k, temp);
            temp.pop_back();
        }
    }

public:
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int> temp;
        sort(nums.begin(), nums.end());
        dfs(0, nums, k, temp);
        return subsetsCount - 1;
    }
};