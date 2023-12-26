// O(target) space optimization with 2 arrays 

class Solution {
private:
    int MOD = 1e9+7;

public:
    int numRollsToTarget(int n, int k, int target) {
        vector<int> prev(target + 1, 0);
        // base case
        prev[0] = 1;

        long long res;
        for(int ind = 1; ind <= n; ind++)
        {
            vector<int> cur(target + 1, 0);
            for(int tar = 1; tar <= target; tar++)
            {
                res = 0;
                for(int die = 1; die <= k && die <= tar; die++)
                {
                    res += prev[tar - die];
                    res %= MOD;
                }
                cur[tar] = res;
            }
            prev = cur;
        }

        return prev[target];
    }
};