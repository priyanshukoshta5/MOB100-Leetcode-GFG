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
    void preOrder(TreeNode *node, string &ans){
        if(node == nullptr)
            return;
        if(ans.length() > 0)
            ans.push_back('(');
        ans.append(to_string(node->val));
        if(node->left == nullptr && node->right == nullptr)
        {
            ans;
        }
        else if(node->left == nullptr)
            ans.append("()");
        preOrder(node->left, ans);
        preOrder(node->right, ans);
        ans.push_back(')');
    }

public:
    string tree2str(TreeNode* root) {
        string ans = "";
        preOrder(root, ans);
        ans.pop_back();
        return ans;
    }
};