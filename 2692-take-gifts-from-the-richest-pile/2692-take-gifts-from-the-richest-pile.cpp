class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> maxH;
        for(int i: gifts)
            maxH.push(i);
        while(k > 0)
        {
            int temp = maxH.top();
            maxH.pop();
            temp = sqrt(temp);
            maxH.push(temp);
            k--;
        }
        long long ans = 0;
        while(!maxH.empty())
        {
            ans += maxH.top();
            maxH.pop();
        }
        return ans;
    }
};