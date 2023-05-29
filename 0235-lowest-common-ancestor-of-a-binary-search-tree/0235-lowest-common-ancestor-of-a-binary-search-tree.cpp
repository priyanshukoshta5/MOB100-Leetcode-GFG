/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    
    
public:
    TreeNode* lca; 
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // TreeNode* lca = nullptr;
        if(p->val > q->val)
            swap(p, q);
        solve(root, p, q);
        return lca;
    }
    
    void solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == nullptr)
            return;
        
        if(p->val <= root->val && root->val <= q->val)
        {
            lca = root;
            return;
        }
        
        solve(root->left, p, q);
        solve(root->right, p, q);
    }
};