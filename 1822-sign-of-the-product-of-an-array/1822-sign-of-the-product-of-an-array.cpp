class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool sign = true;
        for(int i: nums)
        {
            if(i < 0)
                sign = !sign;
            else if(i == 0)
                return 0;
        }
        return sign ? 1:-1;
    }
};