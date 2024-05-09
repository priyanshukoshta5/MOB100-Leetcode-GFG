class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int> ());
        long long ans = 0;
        int i = 0;
        while(k > 0 && (happiness[i] - i) > 0)
        {
            ans += 1LL*(happiness[i] - i);
            i++;
            k--;
        }
        return ans;
    }
};