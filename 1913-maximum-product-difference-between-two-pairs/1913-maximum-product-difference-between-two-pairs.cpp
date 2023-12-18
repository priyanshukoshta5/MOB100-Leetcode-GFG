class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        priority_queue<int> maxH;
        priority_queue<int, vector<int>, greater<int>> minH;
        for(int i: nums)
        {
            maxH.push(i);
            minH.push(i);
            if(maxH.size() > 2) maxH.pop();
            if(minH.size() > 2) minH.pop();
        }

        int min1 = maxH.top(); maxH.pop();
        int min2 = maxH.top(); maxH.pop();
        int max1 = minH.top(); minH.pop();
        int max2 = minH.top(); minH.pop();

        return (max1 * max2) - (min1 * min2);
    }
};