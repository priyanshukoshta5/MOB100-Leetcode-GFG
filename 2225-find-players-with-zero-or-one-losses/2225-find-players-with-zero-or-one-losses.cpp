class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> defeats;
        for(auto i: matches)
        {
            defeats[i[0]] += 0;
            defeats[i[1]]++;
        }

        vector<vector<int>> ans(2);
        for(auto x: defeats)
        {
            if(x.second == 0)
                ans[0].push_back(x.first);
            if(x.second == 1)
                ans[1].push_back(x.first);
        }

        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        return ans;
    }
};