class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();

        int rollsSum = 0;
        for(int i: rolls)
            rollsSum += i;

        int sumOfN = (mean * (m + n)) - rollsSum;

        if(sumOfN < n || sumOfN > (n * 6))
            return {};
        
        vector<int> ans(n);
        int pos = n - 1;
        while(pos >= 0 && sumOfN >= (pos + 1))
        {
            ans[pos] = ceil(sumOfN / (pos + 1));
            sumOfN -= ans[pos];
            pos--;
        }

        return ans;
    }
};