/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// ~Striver

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr)
            return nullptr;
        
        int val = root->val;
        
        // If both(p,q) lies on LEFT, move left
        if(val > p->val && val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        
        // If both(p,q) lies on RIGHT, move right
        if(val < p->val && val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        
        // If not able to determine return root => LCA;
        return root;
    }
};