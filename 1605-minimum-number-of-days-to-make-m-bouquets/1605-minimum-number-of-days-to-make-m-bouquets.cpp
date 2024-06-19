class Solution {
private:
    int isPossible(vector<int> &bloomDay, int m, int k, int maxDay){
        int cnt = 0;
        int streak = 0;
        for(int i: bloomDay)
        {
            if(i <= maxDay)
                streak++;
            else
                streak = 0;
            
            if(streak == k)
            {
                streak = 0;
                cnt++;
            }
            if(cnt == m)
                break;
        }

        return cnt >= m;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((1LL * m * k) > bloomDay.size())
            return -1;
        
        int low = 1;
        int high = 0;
        for(int i: bloomDay)
            high = max(high, i);

        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(isPossible(bloomDay, m, k, mid))
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
};