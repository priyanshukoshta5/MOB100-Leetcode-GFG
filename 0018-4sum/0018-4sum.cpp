class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<vector<int>> ans;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int left = j+1;
                int right = n-1;
                long long target_2 = (long long)target - ((long long)nums[i]+(long long)nums[j]);
                while(left < right)
                {
                    long long sum = (long long)nums[left] + (long long)nums[right];
                    if(sum == target_2)
                    {
                        vector<int> res = {nums[i], nums[j], nums[left], nums[right]};
                        ans.push_back(res);
                        
                        while (left < right && nums[left] == res[2]) left++;
                        while (left < right && nums[right] == res[3]) right--;
                    }
                    else if(sum < target_2)
                        left++;
                    else
                        right--;
                }          
                while((j+1)<n && nums[j+1]==nums[j]) j++;
            }
            while((i+1)<n && nums[i+1]==nums[i]) i++;
        }

        return ans;
    }
};