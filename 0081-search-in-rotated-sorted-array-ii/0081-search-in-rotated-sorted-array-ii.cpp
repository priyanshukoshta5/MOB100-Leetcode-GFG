class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(nums[mid] == target) // element found
                return true;
            else if(nums[low] == nums[mid] && nums[mid] == nums[high])  // shrinking the search space, as we are not sure which half is sorted
            {
                low++;
                high--;
            }
            else if(nums[low] <= nums[mid])  // left part is sorted
            {
                if(nums[low] <= target && target <= nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else    // right part is sorted
            {
                if(nums[mid] <= target && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        return false;
    }
};