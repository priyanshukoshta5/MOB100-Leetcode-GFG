class Solution {
private:
    unordered_map<long long, vector<int>> pos;

    // fix findSlices function
    int findSlices(int cur, int prev, long long diff, vector<int> &nums, vector<vector<int>> &dp){
        // if(dp[prev][ind] != -1)
        //     return dp[prev][ind];

        long long next = 1LL*nums[cur] + diff;
        if(pos.find(next) == pos.end())
            return 0;

        int res = 0;
        for(int k: pos[next])
        {
            if(k < prev)
                break;
            
            res = res + 1 + findSlices(k, cur, diff, nums, dp);
        }

        return dp[prev][cur] = res;
    }

public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++)
            pos[nums[i]].push_back(i);
        // for(auto x: pos)
        //     reverse(pos[x.first].begin(), pos[x.first].end());

        vector<vector<int>> dp(n, vector<int> (n, 0));
        int ans = 0;
        for(int i = 1; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                long long diff = 1LL*nums[j] - 1LL*nums[i];
                long long prev = 1LL*nums[i] - diff;
                if(pos.count(prev)) 
                {
                    for (int k : pos[prev]) 
                    {
                        if (k < i)
                            dp[i][j] += dp[k][i] + 1;
                        else
                            break;
                    }
                }
                // dp[i][j] = findSlices(j, i, diff, nums, dp);
                ans += dp[i][j];
            }
        }

        return ans;
    }
};