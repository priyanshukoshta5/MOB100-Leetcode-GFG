class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int val = *max_element(nums.begin(), nums.end());
        int i = 0;
        int ans = 1;
        while(i < nums.size())
        {
            if(nums[i] == val)
            {
                int cnt = 0;
                while(i < nums.size() && nums[i] == val)
                {
                    i++;
                    cnt++;
                }
                ans = max(ans, cnt);
            }
            else
                i++;
        }
        return ans;
    }
};