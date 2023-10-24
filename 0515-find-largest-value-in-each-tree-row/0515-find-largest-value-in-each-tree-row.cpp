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
    void traverse(TreeNode *node, int depth, vector<int> &ans){
        if(node == nullptr)
            return;

        if(depth == ans.size())
            ans.push_back(node->val);
        else
            ans[depth] = max(ans[depth], node->val);

        traverse(node->left, depth + 1, ans);
        traverse(node->right, depth + 1, ans);
    }

public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        traverse(root, 0, ans);
        return ans;
    }
};