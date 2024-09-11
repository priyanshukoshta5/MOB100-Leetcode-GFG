class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt = 0;
        for(int i = 0; i < 32; i++)
        {
            if(start % 2 != goal % 2)
                cnt++;
            start = start >> 1;
            goal = goal >> 1;
        }
        return cnt;
    }
};