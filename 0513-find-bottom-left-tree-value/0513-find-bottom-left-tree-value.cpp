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
    int depth = -1;
    int value = -1;

    void traverse(TreeNode* node, int d){
        if(node == nullptr)
            return;

        if(depth < d)
        {
            depth = d;
            value = node->val;
        }

        traverse(node->left, d + 1);
        traverse(node->right, d + 1);

        return;
    }

public:
    int findBottomLeftValue(TreeNode* root) {
        traverse(root, 0);
        return value;
    }
};