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
    void solve(TreeNode* node, int dir, int len, int& ans){
        if(node == nullptr)
            return;

        ans = max(ans, len);

        if(dir == 0)
        {
            solve(node->right, 1, len+1, ans);
            solve(node->left, 0, 1, ans);
        }
        if(dir == 1)
        {
            solve(node->left, 0, len+1, ans);
            solve(node->right, 1, 1, ans);
        }
    }

public:
    int longestZigZag(TreeNode* root) {
        int ans = 0;
        solve(root->left, 0, 1, ans);
        solve(root->right, 1, 1, ans);
        return ans;
    }
};