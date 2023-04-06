class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int i: nums)
            freq[i]++;

        // {frequency, number}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minH;
        for(auto x: freq)
        {
            minH.push({x.second, x.first});
            if(minH.size() > k)
                minH.pop();
        }

        vector<int> ans;
        while(!minH.empty())
        {
            ans.push_back(minH.top().second);
            minH.pop();
        }

        return ans;
    }
};