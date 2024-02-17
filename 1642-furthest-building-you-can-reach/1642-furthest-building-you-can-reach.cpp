class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();

        priority_queue<int, vector<int>, greater<int>> largeJumps;     // maxSize = ladders
        int bricksCount = 0;
        int i;
        for(i = 1; i < n; i++)
        {
            if(heights[i - 1] >= heights[i])
                continue;
            
            int jump = heights[i] - heights[i - 1];
            largeJumps.push(jump);
            if(largeJumps.size() > ladders)
            {
                bricksCount += largeJumps.top();
                largeJumps.pop();
            }
            if(bricksCount > bricks)
                break;
        }

        return (i - 1);
    }
};