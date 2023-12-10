class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> transposed;
        for(int j = 0; j < matrix[0].size(); j++)
        {
            vector<int> row;
            for(int i = 0; i < matrix.size(); i++)
                row.push_back(matrix[i][j]);
            transposed.push_back(row);
        }
        return transposed;
    }
};