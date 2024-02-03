class Solution {
private:
    int solve(int i, int j, int curMax, vector<int> &arr, int k, vector<vector<int>> &dp){
        int curLen = j - i;

        if(j == arr.size())
            return (curLen * curMax);
        if(dp[i][j] != -1)
            return dp[i][j];

        // starting a new subarray
        int notTake = (curLen * curMax) + solve(j, j + 1, arr[j], arr, k, dp);  

        // continue current subarray
        int take = 0;
        if(curLen < k)
            take = solve(i, j + 1, max(curMax, arr[j]), arr, k, dp);

        return dp[i][j] = max(notTake, take);
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (n, -1)); 
        return solve(0, 1, arr[0], arr, k, dp);
    }
};