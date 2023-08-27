class Solution {
public:
    bool canCross(vector<int>& stones) {
        // if first jump of '1' unit is not possible
        if((stones[1] - stones[0]) != 1)
            return false;

        int n = stones.size();
        map<int,int> mp;    // {element, index};
        for(int i = 0; i < n; i++)
            mp[stones[i]] = i;

        vector<unordered_set<int>> dp(n);   // {ind, k}

        // initial case
        dp[1].insert(1);    // reaching ind = 1 with k = 1

        for(int ind = 1; ind < n; ind++)
        {
            for(int k: dp[ind])
            {
                // jump1 of k-1
                if(k > 1 && mp.find(stones[ind] + (k-1)) != mp.end())
                    dp[mp[stones[ind] + (k - 1)]].insert(k - 1);

                // jump2 of k
                if(mp.find(stones[ind] + (k)) != mp.end())
                    dp[mp[stones[ind] + (k)]].insert(k);

                // jump3 of k+1
                if(mp.find(stones[ind] + (k+1)) != mp.end())
                    dp[mp[stones[ind] + (k + 1)]].insert(k + 1);

                // base case
                if(!dp[n - 1].empty())    // if we reached last index somehow
                    return true;
            }
        }

        return false;
    }
};