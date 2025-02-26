// ~Editorial

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();

        int totalSum = 0;
        for(int i: nums)
            totalSum = (totalSum + i) % p;

        int target = totalSum % p;
        if(target == 0)
            return 0;

        unordered_map<int, int> mp;
        mp[0] = -1;
        
        int currentSum = 0, minLen = n;
        for(int i = 0; i 
        < n; i++)
        {
            currentSum = (currentSum + nums[i]) % p;
            int needed = (currentSum - target + p) % p;
            if(mp.find(needed) != mp.end())
                minLen = min(minLen, i - mp[needed]);
            mp[currentSum] = i;
        }

        return minLen == n ? -1 : minLen;
    }
};