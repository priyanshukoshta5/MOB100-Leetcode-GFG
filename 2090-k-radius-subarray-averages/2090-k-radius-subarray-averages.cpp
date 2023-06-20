class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k == 0)
            return nums;

        int n = nums.size();
        vector<int> ans(n, -1);
        if(n < (2*k + 1))
            return ans;

        int cur = k;
        int i = 1;
        long long sum = nums[k];
        while(i <= k)
        {
            sum = sum + nums[cur - i] + nums[cur + i];
            i++;
        }

        long long len = 2*k + 1;
        while((cur + k) < n)
        {
            ans[cur] = sum / len;
            sum -= nums[cur - k];
            cur++;
            if((cur + k) < n)
                sum += nums[cur + k];
        }

        return ans;
    }
};