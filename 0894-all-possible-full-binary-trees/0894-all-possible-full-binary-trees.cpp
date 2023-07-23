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
        vector<TreeNode*> res;
        
        if(dp[n].size() != 0)
            return dp[n];
        if(n == 1)
        {
            TreeNode *temp = new TreeNode(0);
            res.push_back(temp);
            return dp[n] = res;
        }
        if(n == 3)
        {
            TreeNode *temp = new TreeNode(0);
            temp->left = new TreeNode(0);
            temp->right = new TreeNode(0);
            res.push_back(temp);
            return dp[n] = res;
        }

        vector<TreeNode*> leftTree;
        vector<TreeNode*> rightTree;

        int a = 1;
        int b = n-2;
        while(a < n)
        {
            leftTree = solve(a, dp);
            rightTree = solve(b, dp);
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
        return solve(n, dp);
    }
};