class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();

        vector<int> temp(score.begin(), score.end());
        sort(temp.begin(), temp.end(), greater<int> ());
        unordered_map<int, string> mp;
        if(n > 0)   mp[temp[0]] = "Gold Medal";
        if(n > 1)   mp[temp[1]] = "Silver Medal";
        if(n > 2)   mp[temp[2]] = "Bronze Medal";
        for(int i = 3; i < n; i++)
            mp[temp[i]] = to_string(i + 1);
        
        vector<string> ans(n);
        for(int i = 0; i < n; i++)
            ans[i] = mp[score[i]];
        return ans;
    }
};