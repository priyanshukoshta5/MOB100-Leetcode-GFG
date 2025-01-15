class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int setBits = 0;
        for(int i = 0; i < 32; i++)
        {
            if(((num2 >> i) & 1) == 1)
                setBits++;
        }

        // cout<<setBits<<endl;

        int ans = 0;
        for(int i = 31; i >= 0 && setBits > 0; i--)
        {
            if(((num1 >> i) & 1) == 1)
            {
                // cout<<"1- "<<i<<endl;
                ans = ans | (1 << i);
                setBits--;
            }
        }

        for(int i = 0; i < 31 && setBits > 0; i++)
        {
            if(((num1 >> i) & 1) == 0)
            {
                // cout<<"2- "<<i<<endl;
                ans = ans | (1 << i);
                setBits--;
            }
        }

        return ans;
    }
};