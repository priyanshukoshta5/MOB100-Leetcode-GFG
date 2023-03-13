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
    bool solve(TreeNode* left, TreeNode* right)
    {
        if(left == nullptr && right == nullptr)
            return true;
        if(left == nullptr || right == nullptr || left->val != right->val)
            return false;

        return solve(left->left, right->right) && solve(left->right, right->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        return solve(root->left,  root->right);
    }
};