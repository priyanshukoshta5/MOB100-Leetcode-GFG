class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int total = 1, withoutZero, zero = 0;
        for(auto i: nums)
        {
            if(i == 0)
            {
                zero++;
                withoutZero = total;
            }
            if(zero == 1 && i != 0)
                withoutZero *= i;
            total *= i;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                if(zero == 1)
                    nums[i] = withoutZero;
                else
                    nums[i] = 0;
            }
            else
                nums[i] = total / nums[i];
        }
        
        return nums;
    }
};