class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        
        vector<int> dp(n + 1, 0);
        dp[n] = 0; // base case;
        
        for(int i = n - 1; i >= 0; i--)
        {
            int curMax = arr[i];
            for(int j = i; j < n && j < (i + k); j++)
            {
                curMax = max(curMax, arr[j]);
                dp[i] = max(dp[i], (curMax * (j - i + 1)) + dp[j + 1]);
            }
        }
        
        return dp[0];
    }
};