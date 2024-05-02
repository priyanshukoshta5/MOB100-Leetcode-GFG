class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> st;
        int ans = -1;
        for(int i: nums)
        {
            if(st.find(i * -1) != st.end())
                ans = max(ans, abs(i));
            st.insert(i);
        }
        return ans;
    }
};