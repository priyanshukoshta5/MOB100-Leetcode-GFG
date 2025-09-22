class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        int maxFreq = 0;
        for(int i: nums){
            freq[i]++;
            maxFreq = max(maxFreq, freq[i]);
        }
        int ans = 0;
        for(auto it: freq){
            if(it.second == maxFreq)
                ans += maxFreq;
        }
        return ans;
    }
};