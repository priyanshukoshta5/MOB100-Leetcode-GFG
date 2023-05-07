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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> zigzag;
        if(root == nullptr)
            return zigzag;

        queue<TreeNode*> q;
        q.push(root);
        
        bool dir = true;        // True means Left->right
        while(q.size() > 0)
        {
            int size = q.size();
            vector<int> row(size);
            
            for(int i=0; i<size; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                
                if(dir == true) row[i] = node->val;
                else row[size-i-1] = node->val;
                
                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
            }
            
            zigzag.push_back(row);
            dir = !dir;
        }

        return zigzag;
    }
};