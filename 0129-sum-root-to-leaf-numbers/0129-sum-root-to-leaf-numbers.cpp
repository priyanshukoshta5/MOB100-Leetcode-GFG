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
    void getSum(TreeNode* node, int num, int& total)
    {
        if(node == nullptr)
            return;
        if(node->left == nullptr && node->right == nullptr)
        {
            total = total + num*10 + node->val;
            return;
        }

        getSum(node->left, num*10+node->val, total);
        getSum(node->right, num*10+node->val, total);
    }
public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        getSum(root, 0, ans);
        return ans;
    }
};