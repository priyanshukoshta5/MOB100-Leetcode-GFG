class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        // first row
        double start = poured;
        vector<double> prev = {start};

        // filling glasses level wise
        bool flag = true;   // true means there is a glass in that level > 1.0
        for(int i = 1; flag != false; i++)
        {
            flag = false;
            vector<double> curr(i + 1, 0.0);
            for(int j = 0; j < i; j++)
            {
                if(prev[j] <= 1.0)
                    continue;

                flag = true;
                double rem = prev[j] - 1.0;
                prev[j] = 1.0;
                double each = rem / 2.0;
                curr[j] += each;
                curr[j + 1] += each;
            }
            if(query_row == i - 1)
                return prev[query_glass];
            prev = curr;
        }

        return 0.0;
    }
};