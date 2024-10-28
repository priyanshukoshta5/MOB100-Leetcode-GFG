class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());

        unordered_map<int, int> mp;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            double d = nums[i];
            double sq = sqrt(d);
            if(ceil(sq) == floor(sq) && mp.find(int(sq)) != mp.end())
            {
                mp[nums[i]] = 1 + mp[sq];
                ans = max(ans, mp[nums[i]]);
            }
            else
                mp[nums[i]] = 1;
        }

        // for(auto x: mp)
        //     cout<<x.first<<" "<<x.second<<endl;

        return (ans == 0) ? -1 : ans;
    }
};