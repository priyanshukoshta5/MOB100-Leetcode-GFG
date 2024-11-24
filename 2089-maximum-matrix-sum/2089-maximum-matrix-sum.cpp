class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        int maxNeg = INT_MIN;
        int negCnt = 0;
        long long ans = 0;
        bool zeroFlag = false;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] < 0)
                {
                    maxNeg = max(maxNeg, matrix[i][j]);
                    negCnt += (matrix[i][j] < 0);
                }
                else if(matrix[i][j] == 0)
                    zeroFlag = true;
                else
                    maxNeg = max(maxNeg, -1 * matrix[i][j]);
                ans += abs(matrix[i][j]);
            }
        }

        if(negCnt % 2 == 0 || zeroFlag == true)
            return ans;
        return ans += 2 * maxNeg;
    }
};