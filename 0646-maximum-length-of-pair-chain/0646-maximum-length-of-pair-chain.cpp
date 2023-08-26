class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();   // size of pairs vector

        // sorting to get the pairs in increasing order of first index
        sort(pairs.begin(), pairs.end());

        // dp vector to store the answer, maximum length ending at each index
        vector<int> dp(n, 1);   // '1' for single pair

        int ans = 1;    // to store the answer

        // for every pair p2, checking all the pairs p1 before it and compute maximum answer
        for(int p2 = 1; p2 < n; p2++)
        {
            for(int p1 = 0; p1 < p2; p1++)
            {
                if(pairs[p1][1] < pairs[p2][0])
                    dp[p2] = max(dp[p2], dp[p1] + 1);
            }
            ans = max(ans, dp[p2]);
        }

        return ans;
    }
};