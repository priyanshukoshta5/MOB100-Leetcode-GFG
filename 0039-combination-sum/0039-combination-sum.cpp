class Solution {
private:
    void combiSum(vector<int>& candidates, int i, int target, vector<int>& temp, vector<vector<int>>& ans){
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }
        if(i == candidates.size())
            return;
            
        if(candidates[i] <= target)
        {
            temp.push_back(candidates[i]);
            combiSum(candidates, i, target-candidates[i], temp, ans);
            temp.pop_back();
        }
        combiSum(candidates, i+1, target, temp, ans);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        combiSum(candidates, 0, target, temp, ans);
        return ans;
    }
};