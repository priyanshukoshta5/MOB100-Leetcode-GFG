class Solution {
private:
    bool check(vector<int> &piles, int h, int mid){
        for(int i = 0; i < piles.size(); i++)
        {
            h -= ((piles[i] / mid) + (piles[i] % mid != 0));
            if(h < 0)
                return false;
        }
        
        return true;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        if(h < piles.size())
            return -1;
        
        int low = 1, high = 0;
        for(int i: piles)
            high = max(high, i);
        
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            // cout<<mid<<endl;
            if(check(piles, h, mid))
                high = mid - 1;
            else
                low = mid + 1;
        }
        
        return low;
    }
};