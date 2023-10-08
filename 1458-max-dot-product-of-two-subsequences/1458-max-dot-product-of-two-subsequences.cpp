class Solution {
private:
    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>> &dp){
        if(i < 0 || j < 0)
            return 0;
        
        if(dp[i][j] != 0)
            return dp[i][j];

        int ans = INT_MIN;

        // take i and j
        ans = (nums1[i] * nums2[j]) + solve(i - 1, j - 1, nums1, nums2, dp);

        // take i or j
        ans = max(ans, max(solve(i - 1, j, nums1, nums2, dp),
                           solve(i, j - 1, nums1, nums2, dp)) );

        return dp[i][j] = ans;
    }

public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(), vector<int> (nums2.size(), 0));
        int ans = INT_MIN;
        for(int i = 0; i < nums1.size(); i++)
        {
            for(int j = 0; j < nums2.size(); j++)
                ans = max(ans, (nums1[i] * nums2[j]) + solve(i - 1, j - 1, nums1, nums2, dp));
        }
        return ans;
    }
};