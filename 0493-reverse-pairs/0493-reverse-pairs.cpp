class Solution {
private:
    void mergeN(vector<int>& nums, int low, int mid, int high, int& ans, vector<int>& temp){
        int p = mid+1;
        for(int i=low; i<=mid; i++)
        {
            while(p<=high && nums[i]>2LL*nums[p])
                p++;
            ans = ans + (p-(mid+1));
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