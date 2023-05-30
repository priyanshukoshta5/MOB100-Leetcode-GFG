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
    void inorder(TreeNode* root, int& k, int& kth){
        if(root == nullptr || k < 0)
            return;

        if(root->left != nullptr)
            inorder(root->left, k, kth);
        k--;
        if(k == 0)
        {
            kth = root->val;
            return;
        }
        if(root->right != nullptr)
            inorder(root->right, k, kth);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int kth = -1;
        inorder(root, k, kth);
        return kth;
    }
};