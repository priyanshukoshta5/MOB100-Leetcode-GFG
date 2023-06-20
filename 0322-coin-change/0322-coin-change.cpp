class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)
            return 0;

        vector<int> prev(amount + 1, 0), cur(amount + 1, 0);
        for(int amt = 0; amt <= amount; amt++)
        {
            if(amt % coins[0] == 0) prev[amt] = amt / coins[0];
            else prev[amt] = 1e9;
        }
        
        for(int i = 1; i < coins.size(); i++)
        {
            for(int amt = 0; amt <= amount; amt++)
            {
                int notTake = 0 + prev[amt];
                int take = 1e9;
                if(coins[i] <= amt)
                    take = 1 + cur[amt - coins[i]];
                cur[amt] = min(take, notTake);
            }
            prev = cur;
        }
        
        return prev[amount] >= 1e9 ? -1 : prev[amount];
    }
};