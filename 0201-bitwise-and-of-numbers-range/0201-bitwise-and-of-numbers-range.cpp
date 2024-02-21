class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = 0;
        for(int b = 31; b >= 0; b--)
        {
            if((left >> b & 1) == (right >> b & 1))
            {
                if((left >> b) & 1 == 1)
                    ans = ans | (1 << b);
            }
            else
                break;
        }
        return ans;
    }
};