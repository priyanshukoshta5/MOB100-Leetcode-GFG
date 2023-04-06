class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int i: nums)
            freq[i]++;

        vector<vector<int>> bucket(nums.size()+1);
        for(auto x: freq)
            bucket[x.second].push_back(x.first);

        vector<int> ans;
        for(int i=nums.size(); i>0 && ans.size()<k; i--)
        {
            for(int j=0; j<bucket[i].size() && ans.size()<k; j++)
                ans.push_back(bucket[i][j]);
        }

        return ans;
    }
};