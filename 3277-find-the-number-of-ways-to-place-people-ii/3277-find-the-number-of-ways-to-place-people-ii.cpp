class Solution {
public:
    bool static compare(vector<int> &a, vector<int> &b){
        if(a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }

    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();

        sort(points.begin(), points.end(), compare);

        int ans = 0;
        for(int i = 0; i < n - 1; i++){
            auto &A = points[i];
            int xMin = A[0] - 1;
            int xMax = INT_MAX;
            int yMin = INT_MIN;
            int yMax = A[1] + 1;

            for(int j = i + 1; j < n; j++){
                auto &B = points[j];
                if(B[0] > xMin && B[0] < xMax && B[1] > yMin && B[1] < yMax){ 
                    ans++;
                    xMin = B[0];
                    yMin = B[1];
                }
            }
        }

        return ans;
    }
};