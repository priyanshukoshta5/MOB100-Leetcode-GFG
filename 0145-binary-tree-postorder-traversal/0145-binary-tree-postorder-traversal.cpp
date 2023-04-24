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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr)
            return {};
        
        vector<int> nums;
        stack<TreeNode*> stk;
        stack<int> vals;
        stk.push(root);
        while(!stk.empty())
        {
            TreeNode *top = stk.top();
            stk.pop();
            
            if(top->left != nullptr)
                stk.push(top->left);
            if(top->right != nullptr)
                stk.push(top->right);
            vals.push(top->val);
        }
        
        while(!vals.empty())
        {
            nums.push_back(vals.top());
            vals.pop();
        }
        return nums;
    }
};