// with the help of editorial

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int ans = 0;
        vector<int> max1Above(m, 0);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] == 1)
                    max1Above[j]++;
                else
                    max1Above[j] = 0;
            }

            vector<int> curr1s;
            for(int i: max1Above)
            {
                if(i != 0)
                    curr1s.push_back(i);
            }
            sort(curr1s.begin(), curr1s.end(), greater<int> ());
            for(int j = 0; j < curr1s.size(); j++)
            {
                int base = j + 1;
                int height = curr1s[j];
                ans = max(ans, base * height);
            }
        }

        return ans;
    }
};