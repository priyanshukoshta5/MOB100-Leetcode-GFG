class Solution {
public:
    int minOperations(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        vector<int> unique(st.begin(), st.end());

        int n = nums.size();
        int ans = INT_MAX;

        for(int i = 0; i < unique.size(); i++)
        {
            int j = upper_bound(unique.begin() + i, unique.end(), n - 1 + unique[i]) - unique.begin();
            int numsBetween = j - i;
            ans = min(ans, n - numsBetween);
            // cout<<i<<" "<<j<<" "<<numsBetween<<endl;
        }

        return ans;
    }
};