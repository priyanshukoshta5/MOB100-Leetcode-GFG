class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size() == 0)
            return ans;
        
        int start = 0, end = 1;
        while(end < nums.size())
        {
            if((1LL*nums[end]-1LL*nums[end-1]) != 1)
            {
                if((start+1) == end)
                    ans.push_back(to_string(nums[start]));
                else
                    ans.push_back(to_string(nums[start]) + "->" + to_string(nums[end-1]));
                start = end;
            }
            end++;
        }
        if((start+1) == end)
            ans.push_back(to_string(nums[start]));
        else
            ans.push_back(to_string(nums[start]) + "->" + to_string(nums[end-1]));
        return ans;
    }
};