class Solution {
private:
    int binS(vector<int>& nums, int low, int high, int target){
        int i = low;
        int j = high;
        int mid = -1;
        while(i <= j)
        {
            mid = i + (j-i)/2;
            if((long long)nums[mid] <= 2*(long long)target)
                i = mid+1;
            else
                j = mid-1;
        }

        return i;
    }

    void mergeN(vector<int>& nums, int low, int mid, int high, int& ans, vector<int>& temp){
        for(int j=mid+1; j<=high; j++)
        {
            int pos = binS(nums, low, mid, nums[j]);
            ans = ans + (mid-pos+1);
        }

        int i = low;
        int j = mid+1;
        int k = low;

        while(i<=mid && j<=high)
        {
            if(nums[i] <= nums[j])
                temp[k++] = nums[i++];
            else
                temp[k++] = nums[j++];
        } 
        while(i<=mid)
            temp[k++] = nums[i++];
        while(j<=high)
            temp[k++] = nums[j++];

        i = low;
        k = low;
        while(i<=high)
            nums[i++] = temp[k++];
    }

    void mergeSortN(vector<int>& nums, int low, int high, int& ans, vector<int>& temp){
        if(low < high){
            int mid = low + (high-low)/2;
            mergeSortN(nums, low, mid, ans, temp);
            mergeSortN(nums, mid+1, high, ans, temp);
            mergeN(nums, low, mid, high, ans, temp);
        }
    }

public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> temp(n);
        mergeSortN(nums, 0, n-1, ans, temp);
        return ans;
    }
};