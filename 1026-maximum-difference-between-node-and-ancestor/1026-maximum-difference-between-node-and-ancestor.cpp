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
    int ans = 0;
    void findMaxDiff(TreeNode *node, int maxi, int mini){
        if(node == nullptr)
            return;
        ans = max(ans, max(abs(node->val - maxi), abs(node->val - mini)));
        maxi = max(maxi, node->val);
        mini = min(mini, node->val);
        findMaxDiff(node->left, maxi, mini);
        findMaxDiff(node->right, maxi, mini);
    }

public:
    int maxAncestorDiff(TreeNode* root) {
        findMaxDiff(root, root->val, root->val);
        return ans;
    }
};