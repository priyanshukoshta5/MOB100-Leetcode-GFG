class Solution {
private:
    int MOD = 1e9+7; 

    long long int countTrees(int i, vector<int> &arr, vector<long long int> &dp){
        // if value already computed, return it
        if(dp[i] != -1)
            return dp[i];

        // node is the value of the node
        int node = arr[i];

        // cnt will store the number of different trees possible
        long long int cnt = 1;

        // only searching till arr[ind1] < arr[i];
        int maxInd = lower_bound(arr.begin(), arr.end(), node) - arr.begin();
        for(int ind1 = 0; ind1 < maxInd; ind1++)
        {
            // if node value is divisible by arr[ind1]
            if(node % arr[ind1] == 0)
            {
                // checking that other value(node / arr[ind1]) is present in arr or not
                int ind2 = lower_bound(arr.begin(), arr.end(), node / arr[ind1]) - arr.begin();
                if(ind2 < arr.size() && arr[ind2] == (node / arr[ind1]))
                {
                    // calculating number of trees
                    cnt = cnt + countTrees(ind1, arr, dp) * countTrees(ind2, arr, dp) ;
                    cnt = cnt % MOD;
                }
            }
        }

        // returning and storeing value of index 'i' for future use
        return dp[i] = cnt;
    }

public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        // sorting arrary as, unique values + to apply binary search
        sort(arr.begin(), arr.end());
        
        // will store the answers for each index
        vector<long long int> dp(arr.size(), -1);

        // will store total number of answers
        long long int ans = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            ans += countTrees(i, arr, dp);
            ans %= MOD;
        }

        return ans;
    }
};