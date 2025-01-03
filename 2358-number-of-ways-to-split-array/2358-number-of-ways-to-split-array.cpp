class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long right = 0;
        for(int i: nums)
            right += i;
        
        long long left = 0;
        int cnt = 0;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            left += nums[i];
            right -= nums[i];
            // cout<<left<<" "<<right<<" "<<(left >= right)<<endl;
            if(left >= right)
                cnt++;
        }

        return cnt;
    }
};