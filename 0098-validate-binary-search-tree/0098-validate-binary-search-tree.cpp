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
public:
    // using long 'low' and 'high' due to the constraints of the problem
    bool isValidBST(TreeNode* root, long low = LONG_MIN, long high = LONG_MAX) {
        if(root == nullptr)
            return true;

        return low < root->val && root->val < high &&
               isValidBST(root->left, low, root->val) &&
               isValidBST(root->right, root->val, high);
    }
};