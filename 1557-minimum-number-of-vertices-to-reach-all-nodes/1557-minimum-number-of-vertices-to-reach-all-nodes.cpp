class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> isReachable(n, 0);
        for(auto e: edges)
            isReachable[e[1]] = 1;
        
        vector<int> ans;
        for(int i=0; i<n; i++)
            if(isReachable[i] == 0)
                ans.push_back(i);

        return ans;
    }
};