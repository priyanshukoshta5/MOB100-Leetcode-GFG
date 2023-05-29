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
    TreeNode* buildBST(vector<int>& preorder, int& i, int bound){
        if(i == preorder.size() || preorder[i] > bound) 
            return nullptr;
        
        TreeNode* node = new TreeNode(preorder[i++]);
        node->left = buildBST(preorder, i, node->val);
        node->right = buildBST(preorder, i, bound);

        return node;
    }
    
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return buildBST(preorder, i, INT_MAX);
    }
};