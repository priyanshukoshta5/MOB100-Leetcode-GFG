class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;
        for(int i = 0; i < n; i++)
            minH.push({nums[i], i});
        
        while(k--)
        {
            auto it = minH.top();
            minH.pop();

            it.first = it.first * multiplier;
            minH.push(it);
            nums[it.second] = it.first;
        }

        return nums;
    }
};