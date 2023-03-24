class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        sort(nums.begin(), nums.end());
        
        int ans = 1;
        int prev = nums[0];
        int streak = 1;
        
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] == prev+1)
                streak++;
                
            else if(nums[i] != prev)
                streak = 1;
            
            prev = nums[i];
            ans = max(ans, streak);
        }
        
        return ans;
    }
};