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
    int traverse(TreeNode *node, string &code){
        if(node == nullptr)
            return 0;

        int val = node->val - 1;
        code[val] = code[val] == '0' ? '1' : '0';
        
        int ans = 0;

        if(node->left == nullptr && node->right == nullptr)
        {
            int one = count(code.begin(), code.end(), '1');
            if(one <= 1)
                ans = 1;
        }
        
        int left = traverse(node->left, code);
        int right = traverse(node->right, code);

        code[val] = code[val] == '0' ? '1' : '0';

        return (ans + left + right);
    }

public:
    int pseudoPalindromicPaths (TreeNode* root) {
        string code = "0000000000";     // freq[num] % 2 for 1-9
        return traverse(root, code);
    }
};