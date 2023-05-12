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
    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, 
                         vector<int>& inorder, int inStart, int inEnd, map<int,int>& index){
        if(preStart > preEnd || inStart > inEnd)
            return nullptr;
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        
        int rootIndex = index[root->val];
        int numsLeft = rootIndex - inStart;
        
        root->left = buildTree(preorder, preStart + 1, preStart + numsLeft,
                               inorder, inStart, rootIndex - 1, index);
        root->right = buildTree(preorder, preStart + numsLeft+1, preEnd,
                                inorder, rootIndex + 1, inEnd, index);
        
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> index;
        for (int i=0 ; i<inorder.size(); i++)
            index[inorder[i]] = i;
        
        return buildTree(preorder, 0, preorder.size()-1,
                         inorder, 0, inorder.size()-1, index);
    }
};