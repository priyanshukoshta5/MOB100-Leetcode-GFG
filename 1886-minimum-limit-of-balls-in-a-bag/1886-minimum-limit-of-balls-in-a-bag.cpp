class Solution {
private:
    bool check(vector<int> &nums, int maxi, int maxOps){
        for(int i: nums)
        {
            if(i > maxi)
            {
                int ops = i / maxi + ((i % maxi) != 0) - 1;
                // cout<<i<<" "<<maxi<<" "<<ops<<endl;
                if(ops > maxOps)
                    return false;
                maxOps -= ops;
            }
        }
        return true;
    }

public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1, r = *max_element(nums.begin(), nums.end());
        while(l <= r)
        {
            int m = l + (r - l) / 2;
            // cout<<m<<endl;
            if(check(nums, m, maxOperations))
                r = m - 1;
            else
                l = m + 1;
        }
        return l;
    }
};