class Solution {
private:
    void combiSum(vector<int>& candidates, int ind, int target, vector<int>& temp, vector<vector<int>>& ans){
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=ind; i<candidates.size(); i++)
        {
            if(i != ind && candidates[i] == candidates[i-1])
                continue;

            if(candidates[i] <= target)
            {
                temp.push_back(candidates[i]);
                combiSum(candidates, i+1, target-candidates[i], temp, ans);
                temp.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        combiSum(candidates, 0, target, temp, ans);
        return ans;
    }
};