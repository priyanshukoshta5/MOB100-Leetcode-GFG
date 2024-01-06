struct Job{
    int start, end, profit;
    Job(int s, int e, int p){
        start = s;
        end = e;
        profit = p;
    }
};

bool compare(Job &a, Job &b){
    return a.end < b.end;
}

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        
        vector<Job> jobs;
        int maxEnd = 0;
        for(int i = 0; i < n; i++)
        {
            jobs.push_back(Job(startTime[i], endTime[i], profit[i]));
            maxEnd = max(maxEnd, endTime[i]);
        }

        sort(jobs.begin(), jobs.end(), compare);     // increasing order of startTime

        map<int,int> dp;    // {endTime, maxProfit on and before that endtime}
        dp[0] = 0;
        for(Job j: jobs)
        {
            int cur = prev(dp.upper_bound(j.start))->second + j.profit;
            if (cur > dp.rbegin()->second)
                dp[j.end] = cur;
        }

        return dp.rbegin()->second;
    }
};