class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> st(arr.begin(), arr.end());
        map<int, int> rank;
        int cnt = 1;
        for(int i: st)
        {
            rank[i] = cnt;
            cnt++;
        }
        vector<int> ans;
        for(int i: arr)
            ans.push_back(rank[i]);
        return ans;
    }
};