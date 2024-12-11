class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int ans = 1;
        for(int i = nums[0]; i <= nums[n-1]; i++)
        {
            int left = lower_bound(nums.begin(), nums.end(), max(0, i - k)) - nums.begin();
            int right = upper_bound(nums.begin(), nums.end(), i + k) - nums.begin();
            left = i - left;
            right = right - i - 1;
            // cout<<i<<" "<<left<<" "<<right<<endl;
            ans = max(ans, 1 + left + right);
        }
        
        return ans;
    }
};