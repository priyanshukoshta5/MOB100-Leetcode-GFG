class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> maxH;
        for(int i: nums)
            maxH.push(i);

        long long ans = 0;
        while(k--)
        {
            long long val = maxH.top();
            maxH.pop();
            ans += val;
            maxH.push(ceil(val / 3.0));
        }

        return ans;
    }
};