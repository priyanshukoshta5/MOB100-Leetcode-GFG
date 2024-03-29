class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int maxElement = *max_element(nums.begin(), nums.end());
        
        queue<int> q;
        long long ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == maxElement)
                q.push(i);

            if(q.size() > k)
                q.pop();

            if(q.size() == k)
                ans = ans + q.front() + 1;
        }

        return ans;
    }
};