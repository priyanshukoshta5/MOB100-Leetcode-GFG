class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();

        int pref = 0, post = 0;
        for(int i: nums)
            post += i;
        
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            int value = (nums[i] * i - pref) + (post - nums[i] * (n - i));
            ans.push_back(value);
            post -= nums[i];
            pref += nums[i];
        }

        return ans;
    }
};