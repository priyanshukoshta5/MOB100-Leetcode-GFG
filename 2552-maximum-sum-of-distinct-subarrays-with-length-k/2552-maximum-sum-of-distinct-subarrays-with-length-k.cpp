class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        long long ans = 0;
        long long sum = 0;
        int i = 0;
        unordered_set<int> st;
        for(int j = 0; j < n; j++)
        {
            while(st.find(nums[j]) != st.end())
            {
                sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            sum += nums[j];
            st.insert(nums[j]);

            if((j - i + 1) == k && st.size() == k)
            {
                ans = max(ans, sum);
                sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }
        }

        return ans;
    }
};