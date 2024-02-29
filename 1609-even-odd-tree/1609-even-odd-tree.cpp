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
    vector<int> temp;   // will store A element on different levels

    bool traverse(TreeNode* node, int d){
        if(node == nullptr)
            return true;
        
        if(d == temp.size())
        {
            if(d % 2 == 0)
                temp.push_back(INT_MIN);
            else
                temp.push_back(INT_MAX);
        }
        
        // violating condition
        if((d % 2) == 0)
        {
            if(temp[d] >= node->val || (node->val % 2) == 0)
                return false;
        }
        else
        {
            if(temp[d] <= node->val || (node->val % 2) == 1)
                return false;
        }
        
        temp[d] = node->val;

        return traverse(node->left, d + 1) && traverse(node->right, d + 1);
    }

public:
    bool isEvenOddTree(TreeNode* root) {
        return traverse(root, 0);
    }
};