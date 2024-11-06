int setBits(int n){
    int cnt = 0;
    while(n > 0)
    {
        cnt += n % 2;
        n = n / 2;
    }
    return cnt;
}

class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(setBits(nums[j - 1]) == setBits(nums[j]) && nums[j - 1] > nums[j])
                    swap(nums[j - 1], nums[j]);
            }
        }
        
        for(int i = 1; i < n; i++)
            if(nums[i - 1] > nums[i])
                return false;
            
        return true;
    }
};