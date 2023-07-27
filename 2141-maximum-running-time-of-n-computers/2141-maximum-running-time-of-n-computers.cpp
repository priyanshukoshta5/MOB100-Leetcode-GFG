class Solution {
private:
    bool isValid(int n, vector<int>& batteries, long long mid){
        int cnt = 0;
        long long curSum = 0;
        for(auto i: batteries)
        {
            curSum += i;
            if(curSum >= mid)
            {
                curSum = curSum % mid;
                cnt++;
            }
            if(cnt >= n)
                return true;
        }
        return false;
    }

public:
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(), batteries.end());

        long long low = 1, high = 0;
        for(int i: batteries)
            high += i;

        long long ansTime = 1;
        while(low <= high)
        {
            long long mid = low + (high - low) / 2;
            if(isValid(n, batteries, mid))
            {
                ansTime = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }

        return ansTime;
    }
};