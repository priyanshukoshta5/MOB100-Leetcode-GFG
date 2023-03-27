class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        int k;
        for(int i=0; i<nums.size(); i++)
        {
            int target = -nums[i];
            int left = i+1, right = nums.size()-1;
            while(left < right)
            {
                int sum = (nums[left]+nums[right]);
                if(sum == target)
                {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    k = nums[left];
                    while(left < right && nums[left] == k) left++;
                    k = nums[right];
                    while(left < right && nums[right] == k) right--;
                }
                else if(sum > target)
                    right--;
                else 
                    left++;
            }
            k = nums[i];
            while((i+1)<nums.size() && nums[i+1] == k) i++;
        }
        
        return ans;
    }
};