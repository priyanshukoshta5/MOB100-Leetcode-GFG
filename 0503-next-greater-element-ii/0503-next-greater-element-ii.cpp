class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);
        stack<int> stk;
        
        for(int i=2*n-1; i>=0; i--)
        {
            while(!stk.empty() && stk.top()<=nums[i%n])
                stk.pop();
            if(i<n && !stk.empty())
                ans[i] = stk.top();
            stk.push(nums[i%n]);
        }

        return ans;
    }
};