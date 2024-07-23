bool compare(pair<int, int> &p1, pair<int, int> &p2){
    if(p1.second != p2.second)
        return p1.second < p2.second;
    return p1.first > p2.first;
}

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int i: nums)
            freq[i]++;
        
        vector<pair<int, int>> v;
        for(auto x: freq)
            v.push_back(x);

        sort(v.begin(), v.end(), compare);

        vector<int> ans;
        for(auto x: v)
        {
            for(int i = 0; i < x.second; i++)
                ans.push_back(x.first);
        }
        return ans;
    }
};