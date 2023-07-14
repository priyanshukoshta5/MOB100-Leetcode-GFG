class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        unordered_map<int,int> dp;
        int ans = 1;
        for(int i: arr)
        {
            int val = i - difference;
            if(dp.find(val) != dp.end())
                dp[i] = 1 + dp[val];
            else
                dp[i] = 1;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};