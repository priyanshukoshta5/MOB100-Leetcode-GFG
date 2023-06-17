class Solution {
private:
    map<pair<int,int>,int> dp;

    int solve(vector<int>& arr1, int i, vector<int>& arr2, int prev){
        if(i == arr1.size())
            return 0;

        if(dp.find({i, prev}) != dp.end())
            return dp[{i, prev}];

        // Do not replace
        int not_rep = -1;
        if(arr1[i] > prev)
            not_rep = solve(arr1, i+1, arr2, arr1[i]);

        // Replace it 
        int rep = -1;
        int ind = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();
        if(ind != arr2.size())
        {
            int val = arr2[ind];
            rep = solve(arr1, i+1, arr2, val); 
        }

        int ans;

        if(not_rep == -1 && rep == -1) ans = -1;
        else if(not_rep == -1)  ans = 1 + rep;     // +1 for 1 operation
        else if(rep == -1) ans = not_rep;
        else ans = min(not_rep, 1 + rep);          // +1 for 1 operation

        return dp[{i, prev}] = ans;
    }

public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        return solve(arr1, 0, arr2, -1);
    }
};