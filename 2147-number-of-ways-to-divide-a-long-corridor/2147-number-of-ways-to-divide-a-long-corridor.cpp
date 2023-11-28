class Solution {
private:
    int MOD = 1e9+7;

public:
    int numberOfWays(string corridor) {
        int n = corridor.size();
        int ans = 1;
        int seats = 0;
        int i = 0;
        while(i < n)
        {
            if(corridor[i] == 'S')
                seats++;

            i++;
            if(seats > 0 && seats % 2 == 0)
            {
                int streak = 0;
                while(i < n && corridor[i] != 'S')
                {
                    streak++;
                    i++;
                }
                // cout<<i<<" "<<streak<<endl;
                if(i < n)
                    ans = (1LL * ans * (streak + 1)) % MOD;
            }
        }

        if(seats == 0 || seats % 2 != 0)
            return 0;
        return ans;
    }
};