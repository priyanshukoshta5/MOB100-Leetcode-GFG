class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> temp(1e4+1, 0);
        for(int i: nums)
            temp[abs(i)]++;
        int j = 0;
        for(int i = 0; i <= 1e4; i++)
        {
            while(j < nums.size() && temp[i] > 0)
            {
                nums[j] = i * i;
                temp[i]--;
                j++;
            }
        }
        return nums;
    }
};