class Solution {
private:
    void mergeSort(vector<int>& nums, int start, int end)
    {
        if(start < end)
        {
            int mid = start + (end-start)/2;
            mergeSort(nums, start, mid);
            mergeSort(nums, mid+1, end);
            merge(nums, start, mid, end);
        }
    }

    void merge(vector<int>& nums, int start, int mid, int end)
    {
        if(start < end)
        {
            vector<int> sortedArr;
            int i = start;
            int j = mid+1;
            while(i<=mid && j<=end)
            {
                if(nums[i] <= nums[j])
                    sortedArr.push_back(nums[i++]);
                else
                    sortedArr.push_back(nums[j++]);
            }
            while(i<=mid)
                sortedArr.push_back(nums[i++]);
            while(j<=end)
                sortedArr.push_back(nums[j++]);
            
            i = start;
            j = 0;
            while(j<sortedArr.size())
            {
                nums[i] = sortedArr[j];
                i++;
                j++;
            }
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};