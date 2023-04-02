class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        
        int low = 0, high = n-1, mid;
        int ans = 0;
        while(low <= high)
        {
            mid = low + (high-low)/2;
            if(mid == 0)
            {
                if(nums[mid] != nums[mid+1])   
                    return nums[mid];
                else
                    low = mid+1;
            }
            else if(mid == n-1)
            {
                if(nums[mid] != nums[mid-1])
                    return nums[mid];
                else
                    high = mid-1;
            }
            else
            {
                if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])
                    return nums[mid];
                else if(nums[mid] == nums[mid-1])
                {
                    int leftNums = mid - (1);
                    if(leftNums%2 == 0)
                        low = mid+1;
                    else
                        high = mid-1;
                }
                else if(nums[mid] == nums[mid+1])
                {
                    int leftNums = mid;
                    if(leftNums%2 == 0)
                        low = mid+1;
                    else
                        high = mid-1;
                }
            }
        }
        return -1;
    }
};