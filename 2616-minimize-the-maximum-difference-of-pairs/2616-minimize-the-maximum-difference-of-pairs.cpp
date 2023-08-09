class Solution {
private:
    // function to check that we can make p pairs with diff <= mid or not
    bool isValid(vector<int> &nums, int p, int mid){
        int i = 1;
        while(i < nums.size())
        {
            if((nums[i] - nums[i-1]) <= mid)
            {
                p--;
                i += 2;
                if(p <= 0)
                    return true;
            }
            else
                i++;
        }

        return false;
    }

public:
    int minimizeMax(vector<int>& nums, int p) {
        // if zero pairs to select -> empty set
        if(p == 0)
            return 0;

        // sorting to get the pairs with minimum differences adjacent to each other
        sort(nums.begin(), nums.end());

        // searching for optimum value of the differences
        int low = 0, high = nums.back() - nums[0];
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(isValid(nums, p, mid))
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
};