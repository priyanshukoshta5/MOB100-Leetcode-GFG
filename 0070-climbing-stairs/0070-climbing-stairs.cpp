class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)
            return 1;
        int plus1 = 1, plus2 = 0, cur = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            cur = plus1 + plus2;
            plus2 = plus1;
            plus1 = cur;
        }
        return cur;
    }
};