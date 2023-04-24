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
    void preOrder(TreeNode* node, vector<int>& nums){
        if(node == nullptr)
            return;
        
        nums.push_back(node->val);
        preOrder(node->left, nums);
        preOrder(node->right, nums);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nums;
        preOrder(root, nums);
        return nums;
    }
};