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
    // int searchPlusSum(TreeNode *root, int low, int high){
    //     if(root == nullptr)
    //         return 0;
        
    //     if(root->val == low)
    //         return low;
    //     else if(root->val < low)
    //         return searchPlusSum()

    //     if(root->val == high)
    //         return high
    // }

public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == nullptr)
            return 0;
        int left = rangeSumBST(root->left, low, high);
        int right = rangeSumBST(root->right, low, high);
        if(low <= root->val && root->val <= high)
            return (left + root->val + right);
        return (left + right);
    }
};