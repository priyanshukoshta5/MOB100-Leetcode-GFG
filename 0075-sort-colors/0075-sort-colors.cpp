class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0;
        int one = 0;
        int two = 0;
        for(int x: nums)
        {
            if(x == 0) zero++;
            if(x == 1) one++;
            if(x == 2) two++;
        }

        int i = 0;
        while(zero > 0)
        {
            nums[i] = 0;
            zero--;
            i++;
        }
        while(one > 0)
        {
            nums[i] = 1;
            one--;
            i++;
        }
        while(two > 0)
        {
            nums[i] = 2;
            two--;
            i++;
        }
    }
};