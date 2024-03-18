class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());

        int arrows = 1;
        int pos = 0;
        for(int i = 0; i < points.size(); i++)
        {
            if(points[pos][1] >= points[i][0])
            {
                points[pos][0] = points[i][0];
                points[pos][1] = min(points[pos][1], points[i][1]);
            }
            else
            {
                arrows++;
                pos = i;
            }
        }

        return arrows;
    }
};