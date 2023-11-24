class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int ans = 0;
        int n = piles.size();
        int cnt = n / 3;
        int pos = n - 2;
        while(cnt--)
        {
            ans += piles[pos];
            pos = pos - 2;
        }
        return ans;
    }
};