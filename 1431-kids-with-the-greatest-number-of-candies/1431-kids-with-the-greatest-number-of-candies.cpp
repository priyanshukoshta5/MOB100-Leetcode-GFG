class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi = 0;
        for(int i: candies)
            maxi = max(maxi, i);
        
        vector<bool> ans;
        for(int i: candies)
            ans.push_back((i+extraCandies) >= maxi);
        
        return ans;
    }
};