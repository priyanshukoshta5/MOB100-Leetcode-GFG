class Solution {
public:
    int minOperations(string s) {
        int cost1 = 0;  // starting with 1
        int cost2 = 0;  // starting with 0
        for(int i = 0; i < s.length(); i++)
        {
            if(i % 2 == 0)
            {
                if(s[i] == '0')
                    cost1++;
                else
                    cost2++;
            }
            else
            {
                if(s[i] == '0')
                    cost2++;
                else
                    cost1++;
            }
        }

        return min(cost1, cost2);
    }
};