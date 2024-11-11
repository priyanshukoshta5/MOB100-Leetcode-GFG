class Solution {
private:
    vector<int> getPrimes(int n)
    {
        vector<int> primes(n+1,1);
        for(int i=2; i<=n; i++)
        {
            for(int j=pow(i,2); j<=n; j+=i)
                primes[j] = 0;
        }
        
        vector<int> res;
        for(int i=2; i<=n; i++)
        {
            if(primes[i] == 1)
                res.push_back(i);
        }
        return res;
    }

    int mySearch(vector<int>& primes, int num, int condition)
    {
        int i = 0;
        while(i<primes.size() && primes[i]<num && (num-primes[i])>condition)
            i++;

        if(i == 0)
            return 0;
        // cout<<condition<<" "<<num<<" "<<primes[i-1]<<endl;
        return primes[i-1];
    }

public:
    bool primeSubOperation(vector<int>& nums) {
        vector<int> primes = getPrimes(1000);
        // for(int i: primes)
        //     cout<<i<<" ";
        // cout<<endl;

        nums[0] -= mySearch(primes, nums[0], 0);
        for(int i=1; i<nums.size(); i++)
        {
            nums[i] -= mySearch(primes, nums[i], nums[i-1]);
            if(nums[i] <= nums[i-1])
                return false;
        }
        
        return true;
    }
};