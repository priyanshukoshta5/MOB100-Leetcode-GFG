class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> minH;     // {sum, {i1, i2}};
        set<pair<int,int>> st;
        
        minH.push({nums1[0] + nums2[0], {0,0}});
        st.insert({0,0});
        
        vector<vector<int>> ans;
        while(k > 0 && minH.size() > 0)
        {
            auto it = minH.top();
            minH.pop();
            
            int val = it.first;
            int i1 = it.second.first;
            int i2 = it.second.second;
            
            // Adding to answer
            ans.push_back({nums1[i1], nums2[i2]});
            
            // Moving i1
            if((i1 + 1) < n1 && st.find({i1 + 1, i2}) == st.end())
            {
                minH.push({nums1[i1+1] + nums2[i2], {i1 + 1, i2}});
                st.insert({i1 + 1, i2});
            }
            
            // Movind i2
            if((i2 + 1) < n2 && st.find({i1, i2 + 1}) == st.end())
            {
                minH.push({nums1[i1] + nums2[i2+1], {i1, i2 + 1}});
                st.insert({i1, i2 + 1});
            }
            
            k--;
        }
        
        return ans;
    }
};