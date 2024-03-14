class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> sumFreq;
        int ans = 0, sum = 0;
        for(int i: nums)
        {
            sum += i;
            if(sum == goal)
                ans++;
            if(sumFreq.find(sum - goal) != sumFreq.end())
                ans += sumFreq[sum - goal];
            sumFreq[sum]++;
        }
        return ans;
    }
};