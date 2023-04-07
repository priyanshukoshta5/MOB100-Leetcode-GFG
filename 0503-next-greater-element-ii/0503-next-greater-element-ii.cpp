class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);
        stack<int> stk;
        for(int i=n-1; i>=0; i--)
            stk.push(nums[i]);

        for(int i=n-1; i>=0; i--)
        {
            while(!stk.empty() && stk.top()<=nums[i])
                stk.pop();
            if(!stk.empty())
                ans[i] = stk.top();
            stk.push(nums[i]);
        }

        return ans;
    }
};