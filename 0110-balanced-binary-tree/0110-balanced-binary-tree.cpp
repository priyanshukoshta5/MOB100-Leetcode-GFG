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
    int traverse(TreeNode* node){
        if(node == nullptr)
            return 0;
        
        int left = traverse(node->left);
        int right = traverse(node->right);
        
        if((abs(left-right)) > 1 || left == -1 || right == -1)
            return -1;
        
        return 1 + max(left, right);
    }
    
    bool isBalanced(TreeNode* root) {
        return traverse(root) != -1;
    }
};