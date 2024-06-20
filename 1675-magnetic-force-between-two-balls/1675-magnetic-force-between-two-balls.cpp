class Solution {
private:
    int isPossible(vector<int>& position, int m, int mid){
        int cnt = 1;
        int prev = position[0];
        for(int i = 1; i < position.size(); i++)
        {
            if(position[i] - prev >= mid)
            {
                cnt++;
                prev = position[i];
                if(cnt == m)
                    return true;
            }
        }
        return false;
    }

public:
    int maxDistance(vector<int>& position, int m) {
        if(position.size() < m)
            return -1;
        
        sort(position.begin(), position.end());

        int low = 0;
        int high = position.back() - position[0];
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(isPossible(position, m, mid))
                low = mid + 1;
            else
                high = mid - 1;
        }

        return high;
    }
};