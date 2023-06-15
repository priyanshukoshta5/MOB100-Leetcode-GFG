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
    int maxLevelSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int ansLevel = -1;
        
        // BFS
        queue<TreeNode*> q;
        q.push(root);
        int lvl = 1;
        while(!q.empty())
        {
            int size = q.size();
            int sum = 0;
            while(size--)
            {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if(node->left != nullptr)
                    q.push(node->left);
                if(node->right != nullptr)
                    q.push(node->right);
            }
            if(maxSum < sum)
            {
                maxSum = sum;
                ansLevel = lvl;
            }
            lvl++;
        }
        
        return ansLevel;
    }
};