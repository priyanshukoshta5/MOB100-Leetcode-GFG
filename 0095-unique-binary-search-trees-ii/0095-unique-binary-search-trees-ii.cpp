/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    vector<TreeNode*> solve(int low, int high, map<pair<int,int>, vector<TreeNode*>> &dp)
    {
        if(low > high)
            return {nullptr};
        if(low == high)
            return {new TreeNode(low)};
        if(dp.find({low,high}) != dp.end())
            return dp[{low,high}];
        
        vector<TreeNode*> trees;
        for(int i = low; i <= high; i++)     // choosing the position of the root in the values {low,...,high}
        {
            vector<TreeNode*> left = solve(low, i - 1, dp);
            vector<TreeNode*> right = solve(i + 1, high, dp);
            for(auto l: left)
            {
                for(auto r: right)
                {
                    trees.push_back(new TreeNode(i, l, r));
                }
            }
        }  

        return dp[{low,high}] = trees;
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        map<pair<int,int>, vector<TreeNode*>> dp;
        return solve(1, n, dp);
    }
};