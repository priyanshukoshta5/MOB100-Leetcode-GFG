class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        
        vector<int> ans(spells.size(), 0);
        for(int i=0; i<spells.size(); i++)
        {
            int left = 0, mid, right = potions.size()-1;
            int res = -1;
            while(left <= right)
            {
                mid = left + (right-left)/2;
                long long total_strength = (long long)spells[i] * (long long)potions[mid];
                if(total_strength >= success)
                {
                    res = mid;
                    right = mid-1;
                }
                else
                    left = mid+1;
            }
            if(res != -1)
                ans[i] = potions.size()-res;
        }
        return ans;
    }
};