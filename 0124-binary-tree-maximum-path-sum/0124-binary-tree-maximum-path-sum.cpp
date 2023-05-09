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
    int traverse(TreeNode* node, int &ans){
        if(node == nullptr)
            return 0;
        
        int left = max(0, traverse(node->left, ans));
        int right = max(0, traverse(node->right, ans));

        ans = max(ans, node->val + left + right);
        
        return node->val + max(left, right);
    }
    
    int maxPathSum(TreeNode* root) {
        int ans = root->val;
        traverse(root, ans);
        return ans;
    }
};