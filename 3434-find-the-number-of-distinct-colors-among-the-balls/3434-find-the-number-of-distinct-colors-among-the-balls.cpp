class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int, int> balls;
        vector<int> ans;
        unordered_map<int, int> mp;
        
        for(auto q: queries)
        {
            int b = q[0];
            int c = q[1];
            
            if(balls.find(b) == balls.end())
            {
                balls[b] = c;
                mp[c]++;
            }
            else if(balls[b] != c)
            {
                mp[balls[b]]--;
                if(mp[balls[b]] == 0)
                    mp.erase(balls[b]);
                mp[c]++;
                balls[b] = c;
            }
            
            ans.push_back(mp.size());
        }
        
        return ans;
    }
};