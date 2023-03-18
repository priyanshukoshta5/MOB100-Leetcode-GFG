class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> maxFromLast(n);
        maxFromLast[n-1] = prices[n-1];
        for(int i=n-2; i>=0; i--)
            maxFromLast[i] = max(prices[i], maxFromLast[i+1]);
        
        int ans = 0;
        for(int i=0; i<n; i++)
            ans = max(ans, maxFromLast[i]-prices[i]);

        return ans;
    }
};