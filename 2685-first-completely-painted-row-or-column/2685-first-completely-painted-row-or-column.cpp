class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int size = arr.size();
        int n = mat.size();
        int m = mat[0].size();

        unordered_map<int, pair<int, int>> mp;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
                mp[mat[i][j]] = {i, j};
        }
        
        vector<int> rowCnt(n, m);
        vector<int> colCnt(m, n);
        for(int i = 0; i < size; i++)
        {
            auto it = mp[arr[i]];
            int r = it.first;
            int c = it.second;
            rowCnt[r]--;
            colCnt[c]--;
            if(rowCnt[r] == 0 || colCnt[c] == 0)
                return i;
        }

        return -1;
    }
};