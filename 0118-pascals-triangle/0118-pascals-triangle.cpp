class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        
        int n=1;
        while(n < numRows)
        {
            ans.push_back({1});
            for(int i=1; i<ans[n-1].size(); i++)
                ans[n].push_back(ans[n-1][i-1]+ans[n-1][i]);
            ans[n].push_back(1);        
            n++;
        }
        
        return ans;
    }
};