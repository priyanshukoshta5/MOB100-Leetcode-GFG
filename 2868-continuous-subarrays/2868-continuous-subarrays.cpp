class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();

        int i = 0, j = 0;
        long long cnt = 0;
        map<int, int> freq;
        while(j < n) 
        {
            freq[nums[j]]++;

            while(freq.rbegin()->first - freq.begin()->first > 2) 
            {
                freq[nums[i]]--;
                if (freq[nums[i]] == 0)
                    freq.erase(nums[i]);

                i++;
            }

            cnt= cnt + (j - i + 1);
            j++;
        }

        return cnt;
    }
};