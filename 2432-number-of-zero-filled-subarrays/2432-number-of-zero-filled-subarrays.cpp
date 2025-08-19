class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        long long len = 0;
        for(int i: nums){
            if(i != 0){
                ans = ans + (len * (len + 1)) / 2;
                len = 0;
            }
            else
                len++;
        }
        ans = ans + (len * (len + 1)) / 2;
        return ans;
    }
};