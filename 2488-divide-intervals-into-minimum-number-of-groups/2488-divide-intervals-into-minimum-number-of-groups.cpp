class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> minH;
        minH.push(0);
        int grps = 0;
        for(auto i: intervals)
        {
            if(minH.top() < i[0])
            {
                minH.pop();
            }
            minH.push(i[1]);
            grps = max(grps, int(minH.size()));
        }
        return grps;
    }
};