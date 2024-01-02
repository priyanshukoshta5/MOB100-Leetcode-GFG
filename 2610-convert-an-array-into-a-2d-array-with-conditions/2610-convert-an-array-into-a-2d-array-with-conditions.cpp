class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> freq;
        vector<vector<int>> ans;
        for(int i: nums)
        {
            freq[i]++;
            if(ans.size() < freq[i])
                ans.push_back({i});
            else
                ans[freq[i] - 1].push_back(i);
        }
        return ans;
    }
};