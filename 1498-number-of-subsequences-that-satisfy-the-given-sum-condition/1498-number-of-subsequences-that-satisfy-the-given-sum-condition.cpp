class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        // editorial refered

        int n = nums.size();
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        
        int MOD = 1000000007;

        vector<int> power(n);
        power[0] = 1;
        for (int i = 1; i < n; ++i)
            power[i] = (power[i - 1] * 2) % MOD;

        long long ans = 0;
        for(int i=0; i<n; i++)
        {
            int l=0, r=n-1, m;
            while(l <= r)
            {
                m = l + (r-l)/2;
                if((arr[i] + arr[m]) <= target)
                    l = m+1;
                else
                    r = m-1;
            }
            l--;
            if(l >= i)
            {
                ans += power[l-i];
                ans %= MOD;
            }
        }
        
        return ans;
    }
};