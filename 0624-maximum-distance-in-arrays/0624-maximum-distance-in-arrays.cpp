class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int m = arrays.size();

        int ans = 0;

        int preMaxi, preMini;
        for(int i = 0; i < m; i++)
        {
            int n = arrays[i].size();
            if(i == 0)
            {
                preMaxi = arrays[i][n - 1];
                preMini = arrays[i][0];
                continue;
            }

            ans = max(ans, abs(preMini - arrays[i][n - 1]));
            ans = max(ans, abs(preMaxi - arrays[i][0]));

            preMaxi = max(preMaxi, arrays[i][n - 1]);
            preMini = min(preMini, arrays[i][0]);
        }

        int postMaxi, postMini;
        for(int i = m - 1; i >= 0; i--)
        {
            int n = arrays[i].size();
            if(i == m - 1)
            {
                postMaxi = arrays[i][n - 1];
                postMini = arrays[i][0];
                continue;
            }

            ans = max(ans, abs(postMaxi - arrays[i][n - 1]));
            ans = max(ans, abs(postMini - arrays[i][0]));

            postMaxi = max(postMaxi, arrays[i][n - 1]);
            postMini = min(postMini, arrays[i][0]);
        }

        return ans;
    }
};