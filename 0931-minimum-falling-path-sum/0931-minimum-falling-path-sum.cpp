class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> next = matrix[n - 1];
        for(int i = n - 2; i >= 0; i--)
        {
            vector<int> cur(n, INT_MAX);
            for(int j = 0; j < n; j++)
            {
                cur[j] = min(cur[j], matrix[i][j] + next[j]); // down
                if((j - 1) >= 0)    // left diagonal
                    cur[j] = min(cur[j], matrix[i][j] + next[j - 1]);
                if((j + 1) < n)     // right diagonal
                    cur[j] = min(cur[j], matrix[i][j] + next[j + 1]);
            }
            next = cur;
        }
        int ans = next[0];
        for(auto i: next)
            ans = min(ans, i);
        return ans;
    }
};