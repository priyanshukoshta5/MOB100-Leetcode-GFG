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
    void inOrder(TreeNode *node, vector<int> &arr){
        if(node == nullptr)
            return;
        inOrder(node->left, arr);
        arr.push_back(node->val);
        inOrder(node->right, arr);
    }

    TreeNode *constructBST(int l, int r, vector<int> &arr){
        if(l > r)
            return nullptr;
        if(l == r)
            return new TreeNode(arr[l]);
        int mid = l + (r - l) / 2;
        TreeNode *node = new TreeNode(arr[mid]);
        node->left = constructBST(l, mid - 1, arr);
        node->right = constructBST(mid + 1, r, arr);
        return node;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        inOrder(root, arr);
        return constructBST(0, arr.size() - 1, arr);
    }
};