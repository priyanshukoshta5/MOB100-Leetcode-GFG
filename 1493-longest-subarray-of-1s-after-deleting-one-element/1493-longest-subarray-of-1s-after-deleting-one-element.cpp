class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int prevStreak = 0, curStreak = 0;
        int ans = 0;
        
        for(int i: nums)
        {
            if(i == 1)
                curStreak++;
            else
            {
                ans = max(ans, prevStreak + curStreak);
                prevStreak = curStreak;
                curStreak = 0;
            }
        }
        ans = max(ans, prevStreak + curStreak);
        if(ans == nums.size())
            ans--;
        
        return ans;
    }
};