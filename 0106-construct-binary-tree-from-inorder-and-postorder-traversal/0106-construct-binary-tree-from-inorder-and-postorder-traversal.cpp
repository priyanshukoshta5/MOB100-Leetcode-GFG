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
    TreeNode* buildTree(vector<int>& inorder, int inStart, int inEnd,
                        vector<int>& postorder, int postStart, int postEnd, map<int,int>& index){
        
        if(inStart > inEnd || postStart > postEnd)
            return nullptr;
        
        TreeNode* root = new TreeNode(postorder[postEnd]);
        
        int rootIndex = index[root->val];
        int numsLeft = rootIndex - inStart;
        
        root->left = buildTree(inorder, inStart, rootIndex-1,
                               postorder, postStart, postStart+numsLeft-1, index);
        root->right = buildTree(inorder, rootIndex+1, inEnd,
                                postorder, postStart+numsLeft, postEnd-1, index);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> index;
        for(int i=0; i<inorder.size(); i++)
            index[inorder[i]] = i;
        
        return buildTree(inorder, 0, inorder.size()-1,
                         postorder, 0, postorder.size()-1, index);
    }
};