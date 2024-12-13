class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> minH;
        for(int i = 0; i < n; i++)
            minH.push({nums[i], i});

        vector<bool> vis(n, false);
        long long score = 0;
        while(!minH.empty())
        {
            auto it = minH.top(); minH.pop();
            int val = it.first;
            int ind = it.second;

            if(vis[ind])
                continue;
            
            score = score + val;
            vis[ind] = true;
            if((ind - 1) >= 0) vis[ind - 1] = true;
            if((ind + 1) < n) vis[ind + 1] = true;
        }

        return score;
    }
};