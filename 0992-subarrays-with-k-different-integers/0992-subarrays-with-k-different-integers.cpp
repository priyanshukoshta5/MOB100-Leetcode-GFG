// ~editorial

class Solution {
private:
    int countSubarraysWithAtMostKDistinct(vector<int>& nums, int k){
        int n = nums.size();
        
        int i = 0, j = 0;
        unordered_map<int, int> freq;
        int ans = 0;
        while(j < n)
        {
            freq[nums[j]]++;

            while(i <= j && freq.size() > k)
            {
                freq[nums[i]]--;
                if(freq[nums[i]] == 0)
                    freq.erase(nums[i]);
                i++;
            }

            ans += (j - i + 1);

            j++;
        }

        return ans;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return countSubarraysWithAtMostKDistinct(nums,k) - 
                countSubarraysWithAtMostKDistinct(nums,k-1);
    }
};