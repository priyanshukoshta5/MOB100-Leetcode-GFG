class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2, int i1, int i2, vector<vector<int>>& dp){
        if(i1 == -1 || i2 == -1)
            return 0;

        if(dp[i1][i2] != -1)
            return dp[i1][i2];

        int res;
        if(nums1[i1] == nums2[i2])
            res = 1 + solve(nums1, nums2, i1-1, i2-1, dp);
        else 
            res = max(solve(nums1, nums2, i1-1, i2, dp), solve(nums1, nums2, i1, i2-1, dp));

        return dp[i1][i2] = res;
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> dp(n1+1, vector<int> (n2+1, -1));
        return solve(nums1, nums2, n1-1, n2-1, dp);
    }
};