class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();

        vector<vector<int>> groups(n + 1);
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++)
        {
            if(groupSizes[i] == 1)
                ans.push_back({i});
            else
                groups[groupSizes[i]].push_back(i);
        }

        bool newGroup = true;
        for(int g = 1; g <= n; g++)
        {
            if(groups[g].size() == 0)
                continue;

            for(int p: groups[g])
            {
                if(newGroup == true)
                {
                    ans.push_back({p});
                    newGroup = false;
                }
                else
                {
                    ans.back().push_back(p);
                    if(ans.back().size() == g)
                        newGroup = true;
                }
            }
        }

        return ans;
    }
};