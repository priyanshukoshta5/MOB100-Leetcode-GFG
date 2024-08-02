class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int windowSize = count(nums.begin(), nums.end(), 1);
        if(windowSize == nums.size() || windowSize == 1)
            return 0;

        int i = 0, j = 0;
        int cnt1 = 0;
        int ans = windowSize;
        while(j < nums.size())
        {
            if(nums[j] == 1)
                cnt1++;
            if((j - i + 1) == windowSize)
            {
                ans = min(ans, windowSize - cnt1);
                if(nums[i] == 1)
                    cnt1--;
                i++;
            }
            j++;
        }
        j = 0;
        while(j < windowSize && i < nums.size())
        {
            if(nums[j] == 1)
                cnt1++;
            ans = min(ans, windowSize - cnt1);
            if(nums[i] == 1)
                cnt1--;
            i++;
            j++;
        }
        return ans;
    }
};