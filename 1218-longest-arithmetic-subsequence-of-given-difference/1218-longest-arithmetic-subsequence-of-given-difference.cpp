class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        map<int,int> dp = {{arr[0], 1}};
        int ans = 1;
        for(int i = 1; i < n; i++)
        {
            int val = arr[i] - difference;
            if(dp.find(val) != dp.end())
                dp[arr[i]] = max(dp[arr[i]], 1 + dp[val]);
            else
                dp[arr[i]] = 1;
            ans = max(ans, dp[arr[i]]);
        }
        return ans;
    }
};