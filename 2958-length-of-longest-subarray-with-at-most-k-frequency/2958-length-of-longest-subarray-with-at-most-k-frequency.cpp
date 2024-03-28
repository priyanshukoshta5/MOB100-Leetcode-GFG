class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        priority_queue<pair<int,int>> maxH;
        int ans = 1;
        int i = 0;
        for(int j = 0; j < nums.size(); j++)
        {
            freq[nums[j]]++;
            maxH.push({freq[nums[j]], nums[j]});
            if(maxH.top().first <= k)
                ans = max(ans, j - i + 1);
            else
            {
                while(i <= j && maxH.top().first > k)
                {
                    freq[nums[i]]--;
                    while(freq[maxH.top().second] < maxH.top().first)
                    {
                        maxH.pop();
                        maxH.push({freq[nums[i]], nums[i]});
                    } 
                    i++;
                }
            }
        }
        return ans;
    }
};