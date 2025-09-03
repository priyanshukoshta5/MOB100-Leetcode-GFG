// Editorial

class Solution {
public:
    bool static compare(vector<int> &a, vector<int> &b){
        if(a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }

    int numberOfPairs(vector<vector<int>>& points) {
        int ans = 0;
        sort(points.begin(), points.end(), compare);

        for (int i = 0; i < points.size() - 1; i++) {
            const auto& pointA = points[i];
            int xMin = pointA[0] - 1;
            int xMax = INT_MAX;
            int yMin = INT_MIN;
            int yMax = pointA[1] + 1;

            for (int j = i + 1; j < points.size(); j++) {
                const auto& pointB = points[j];
                if (pointB[0] > xMin && pointB[0] < xMax && pointB[1] > yMin &&
                    pointB[1] < yMax) {
                    ans++;
                    xMin = pointB[0];
                    yMin = pointB[1];
                }
            }
        }
        return ans;
    }
};