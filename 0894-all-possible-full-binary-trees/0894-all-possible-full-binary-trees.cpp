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
    vector<TreeNode*> solve(int n, vector<vector<TreeNode*>> &dp){
        if(dp[n].size() != 0)
            return dp[n];
        
        vector<TreeNode*> res;

        int a = 1;
        int b = n-2;
        while(a < n)
        {
            vector<TreeNode*> leftTree = solve(a, dp);
            vector<TreeNode*> rightTree = solve(b, dp);
            for(TreeNode* l: leftTree)
            {
                for(TreeNode* r: rightTree)
                {
                    TreeNode* temp1 = new TreeNode(0, l, r);
                    res.push_back(temp1);
                }
            }

            a += 2;
            b -= 2;
        }

        return dp[n] = res;
    }

public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2 == 0)
            return {};

        vector<vector<TreeNode*>> dp(n+1);
        dp[1].push_back(new TreeNode(0));
        return solve(n, dp);
    }
};