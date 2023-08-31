class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int,int>> intervals;
        for(int i = 0; i <= n; i++)
        {   
            if(ranges[i] == 0)  // only add interval if its range is greater than 0
                continue;
            pair<int,int> range = {max(0, i - ranges[i]), min(n, i + ranges[i])};
            intervals.push_back(range);
        }

        // sorting intervals using left value of interval
        sort(intervals.begin(), intervals.end());

        // if we do not have any interval or if we cannot include start 0
        if(intervals.size() == 0 || intervals[0].first != 0)
            return -1;

        int ans = 0;    // initial answer
        int ind = 0;    // current position in intervals vector
        int prev = 0;   // current right end of interval

        while(ind < intervals.size() && prev != n)
        {
            int right = prev;   
            int ansInt = -1;    

            // searching from ind to intervals.end for the largest range which includes prev
            while(ind < intervals.size())
            {
                if(intervals[ind].first <= prev && right < intervals[ind].second)
                {
                    right = intervals[ind].second;
                    ansInt = ind;
                }
                ind++;
            }
            
            // if there is no range available
            if(ansInt == -1)
                return -1;

            // updating ind, prev, ans varibles
            ind = ansInt + 1;
            prev = right;
            ans++;
        }

        // if we reached the end of intervals and not reached last position, return -1
        if(prev != n)
            return -1;
        
        return ans;
    }
};