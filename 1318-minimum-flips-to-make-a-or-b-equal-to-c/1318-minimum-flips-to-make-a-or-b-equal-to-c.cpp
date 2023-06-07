class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;
        while(a > 0 || b > 0 || c > 0)
        {
            int bit_A = a % 2;
            int bit_B = b % 2;
            int bit_C = c % 2;
            
            if(bit_C == 1 && bit_A == 0 && bit_B == 0)
                cnt++;
            else if(bit_C == 0)
                cnt += bit_A + bit_B;

            a = a / 2;
            b = b / 2;
            c = c / 2;
        }
        return cnt;
    }
};