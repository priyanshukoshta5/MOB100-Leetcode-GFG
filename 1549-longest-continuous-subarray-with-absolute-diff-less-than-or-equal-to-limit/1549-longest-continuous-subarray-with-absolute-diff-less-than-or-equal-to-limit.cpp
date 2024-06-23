class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        priority_queue<pair<int, int>> maxH;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;
        int ans = 0;
        int i = 0, j = 0;
        while(j < nums.size())
        {
            maxH.push({nums[j], j});
            minH.push({nums[j], j});
            // cout<<i<<" "<<j<<endl;

            if(maxH.top().first - minH.top().first <= limit)
                ans = max(ans, j - i + 1);
            else
            {
                while(i <= j && maxH.top().first - minH.top().first > limit)
                {
                    while(maxH.top().second <= i)
                        maxH.pop();
                    while(minH.top().second <= i)
                        minH.pop();
                    i++;
                }
            }

            j++;
        }

        return ans;
    }
};