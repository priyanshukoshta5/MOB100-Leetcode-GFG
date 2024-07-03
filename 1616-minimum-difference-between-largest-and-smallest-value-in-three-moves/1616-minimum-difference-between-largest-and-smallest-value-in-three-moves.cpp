class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n <= 4)
            return 0;
        
        priority_queue<int> minH;
        priority_queue<int, vector<int>, greater<int>> maxH;
        for(int i: nums)
        {
            minH.push(i);
            maxH.push(i);
            if(minH.size() > 4)
            {
                minH.pop();
                maxH.pop();
            }
        }

        vector<int> small, large;
        while(!minH.empty())
        {
            small.push_back(minH.top()); minH.pop();
            large.push_back(maxH.top()); maxH.pop();
        }

        // for(int i = 0; i < 4; i++)
        //     cout<<large[i]<<" "<<small[3 - i]<<endl;

        int ans = INT_MAX;

        ans = min(ans, large[0] - small[3]);    // removed 3 left, 0 right
        ans = min(ans, large[1] - small[2]);    // removed 2 left, 1 right
        ans = min(ans, large[2] - small[1]);    // removed 1 left, 2 right
        ans = min(ans, large[3] - small[0]);    // removed 0 left, 3 right

        return ans;
    }
};