class Solution {
private:
    int MOD = 1e9+7;

    long getRev(int n){
        long rev = 0;
        while(n > 0)
        {
            rev = rev * 10;
            rev += n % 10;
            n = n / 10;
        }
        return rev;
    }

public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<long, int> revFreq;
        for(int i: nums)
        {
            int rev = getRev(i);
            revFreq[i - rev]++;
        }

        long long int ans = 0;
        for(auto x: revFreq)
        {
            long long int freq = x.second;
            ans = ans + (freq * (freq - 1)) / 2;
            ans = ans % MOD;
        }
        return ans;
    }
};