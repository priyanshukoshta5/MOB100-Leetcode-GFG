class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n+1, 0);
        for(auto i: nums)
            freq[i]++;
        
        for(int i=1; i<=n; i++)
            if(freq[i]>1)
                return i;
        
        return -1;
    }
};