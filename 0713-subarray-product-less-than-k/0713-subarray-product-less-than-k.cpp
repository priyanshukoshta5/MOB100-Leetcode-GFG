class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            long long prod = 1;
            for(int j = i; j < n; j++)
            {
                prod = 1LL * prod * nums[j];
                if(prod < k)
                    cnt++;
                else if(prod > k)
                    break;
            }
        }
        return cnt;
    }
};