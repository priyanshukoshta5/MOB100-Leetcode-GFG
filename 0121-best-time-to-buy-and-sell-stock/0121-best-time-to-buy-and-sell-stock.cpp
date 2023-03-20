class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        int maxi = prices[n-1];
        for(int i=n-1; i>=0; i--)
        {
            maxi = max(maxi, prices[i]);
            ans = max(ans, maxi-prices[i]);            
        }
        return ans;
    }
};