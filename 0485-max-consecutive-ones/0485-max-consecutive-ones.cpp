class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int i = -1, j = 0;
        while(j < nums.size())
        {
            while(j<nums.size() && nums[j] == 1) j++;
            ans = max(ans, j-i-1);
            i = j;
            j++;
        }
        
        return ans;
    }
};