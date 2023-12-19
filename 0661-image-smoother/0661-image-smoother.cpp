class Solution {
private:
    bool isValid(int r, int c, int n, int m){
        return r >= 0 && r < n && c >= 0 && c < m;
    }

public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m = img[0].size();

        vector<vector<int>> filtered(n, vector<int> (m));

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int cnt = 0;
                int sum = 0;
                for(int r = i - 1; r <= (i + 1); r++)
                {
                    for(int c = j - 1; c <= (j + 1); c++)
                    {
                        if(isValid(r, c, n, m))
                        {
                            cnt++;
                            sum += img[r][c];
                        }
                    }
                }
                filtered[i][j] = sum / cnt;
            }
        }

        return filtered;
    }
};