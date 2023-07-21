class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        int ans = 1;
        vector<int> length(n+1, 1);
        vector<int> count(n, 1);
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[j] < nums[i])
                {
                    if((length[j] + 1) > length[i])
                    {
                        length[i] = length[j] + 1;
                        count[i] = count[j];
                    }
                    else if((length[j] + 1) == length[i])
                        count[i] += count[j];
                }
            }
            ans = max(ans, length[i]);
        }

        int ansCnt = 0;
        for(int i = 0; i < n; i++)
            if(length[i] == ans)
                ansCnt += count[i];

        return ansCnt;
    }
};