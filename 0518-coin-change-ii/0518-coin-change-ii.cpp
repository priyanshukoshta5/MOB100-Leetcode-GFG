class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        
        vector<int> prev(amount + 1, 0), cur(amount + 1, 0);
        for(int s = 0; s <= amount; s++)
            if(s % coins[0] == 0)
                prev[s] = 1;
        
        for(int i = 1; i < n; i++)
        {
            for(int s = 0; s <= amount; s++)
            {
                int notTake = prev[s];
                int take = 0;
                if(coins[i] <= s)
                    take = cur[s - coins[i]];
                    
                cur[s] = notTake + take;
            }
            prev = cur;
        }
        
        return prev[amount];
    }
};