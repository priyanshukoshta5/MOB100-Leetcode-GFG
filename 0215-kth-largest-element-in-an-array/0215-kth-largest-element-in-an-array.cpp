class Solution {
public:
    int partition(vector<int>& nums, int left, int right){
        int pivot = nums[left];
        int l = left+1;
        int r = right;
        // sorting in decreasing, ie left side is greater while right side is smaller.
        while(l <= r)
        {
            if(nums[l] < pivot && nums[r] > pivot)
            {
                swap(nums[l], nums[r]);
                l++;
                r--;
            }
            if(nums[l] >= pivot)
                l++;
            if(nums[r] <= pivot)
                r--;
        }
        swap(nums[left], nums[r]);
        return r;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size()-1;
        while(left <= right)
        {
            int pos = partition(nums, left, right);
            if(pos == (k-1))
                return nums[pos];
            else if(pos < (k-1))
                left = pos+1;
            else
                right = pos-1;
        }
        return -1;
    }
};